/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_destroy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:01:50 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/13 17:01:12 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "entities_bonus.h"
#include "libft.h"

void	destroy_all_anims(t_game *game)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (i < NB_MAPS)
	{
		j = 0;
		while (j < MAP_NB_IDS)
		{
			destroy_animation_textures(game->anims[i][j].textures, \
				game->mlx.mlx_ptr);
			j++;
		}
		i++;
	}
}

/**
 * @brief Destroys the given t_game
 * @param game The structure to destroy
*/
void	t_game_destroy(t_game *game)
{
	if (game == NULL)
		return ;
	destroy_game_uis(game, &game->uis);
	destroy_all_anims(game);
	destroy_radar(&game->radar, game->mlx.mlx_ptr);
	t_mlx_destroy(&game->mlx);
	free_maps(game->maps);
	ft_lstclear(&game->sprites, free);
	ft_lstclear(&game->bullets, free);
	ft_lstclear(&game->entities, t_entity_destroy);
}

void	t_game_destroy_and_exit(t_game *game)
{
	if (game != NULL)
		t_game_destroy(game);
	exit(EXIT_SUCCESS);
}
