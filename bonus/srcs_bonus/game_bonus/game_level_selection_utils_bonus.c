/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_level_selection_utils_bonus.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:47:03 by mhotting          #+#    #+#             */
/*   Updated: 2024/10/02 22:40:05 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "door_bonus.h"
#include "entities_bonus.h"
#include "sprite_bonus.h"
#include "error_bonus.h"
#include "libft.h"

bool	game_load_map(t_game *game, size_t map_index)
{
	bool	load_ok;

	if (game == NULL || map_index > NB_MAPS)
		return (false);
	game->map = &game->maps[map_index];
	game->anim = game->anims[map_index];
	restore_doors(game->map->doors, game->map->door_count);
	load_ok = \
		t_player_init(&game->player, game->map, game)
		&& init_sprites(game)
		&& init_entities(game)
		&& init_map_draw(&game->map->draw, game->map, game)
		&& init_radar(&game->radar, &game->mlx)
		&& init_weapons(game)
		&& init_player_weapons(game, &game->player.weapon_info)
		&& init_hud(game, &game->hud);
	if (!load_ok)
		error_exit(game, ERR_MAP_LOAD);
	game->state = STATE_PLAYING;
	game->curr_map_index = map_index;
	game->game_end_loop_count = 0;
	return (true);
}

void	game_unload_map(t_game *game)
{
	size_t	i;

	if (game == NULL)
		return ;
	destroy_radar(&game->radar, game->mlx.mlx_ptr);
	ft_lstclear(&game->sprites, free);
	ft_lstclear(&game->bullets, free);
	ft_lstclear(&game->entities, t_entity_destroy);
	i = 0;
	while (i < game->map->lines_count)
	{
		ft_strlcpy(game->map->tiles[i], game->map->tiles_save[i], \
			ft_strlen(game->map->tiles[i]) + 1);
		i++;
	}
	game->map = NULL;
	game->anim = NULL;
	game->curr_map_index = NO_MAP_LOADED_INDEX;
	ft_bzero(&game->player, sizeof(t_player));
}
