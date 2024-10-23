/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:02:42 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/13 17:00:05 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "event_handlers_bonus.h"
#include "mlx.h"
#include "error_bonus.h"
#include "cub3d_bonus.h"

static bool	init_textures(
	t_game *game,
	t_map *map,
	t_animation anim[MAP_NB_IDS]
)
{
	size_t			index;
	t_mlx_coords	*texture_size;
	char			*filename;
	t_image			texture;

	index = 0;
	while (index < MAP_NB_IDS)
	{
		filename = map->textures[index];
		texture_size = &map->texture_size[index];
		if (filename == NULL || filename[0] == '\0')
			return (error_print_string(ERR_MISSING_TEXTURES, filename), false);
		if (!check_extension(filename, ".xpm"))
			return (error_print_string(ERR_TEXTURE_EXTENSION, filename), false);
		if (!t_image_import_file(&texture, filename, game->mlx.mlx_ptr, NULL))
			return (error_print_string(ERR_INIT_TEXTURES, filename), false);
		anim[index].textures = create_animation_textures(&texture, \
			texture_size, game->mlx.mlx_ptr, filename);
		mlx_destroy_image(game->mlx.mlx_ptr, texture.ptr);
		if (anim[index].textures == NULL)
			return (false);
		index++;
	}
	return (true);
}

static bool	init_all_map_textures(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < NB_MAPS)
	{
		if (!init_textures(game, &game->maps[i], game->anims[i]))
			return (false);
		i++;
	}
	return (true);
}

static bool	init_draw_thread_args(
	t_game *game,
	t_draw_thread_arg draw_thread_args[NB_DRAW_THREADS]
)
{
	size_t	i;

	if ((int) NB_DRAW_THREADS <= 0 || (int) NB_DRAW_THREADS >= 32)
		return (false);
	draw_thread_args[0].game = game;
	draw_thread_args[0].start = 0;
	draw_thread_args[0].end = WIN_WIDTH / NB_DRAW_THREADS;
	i = 1;
	while (i < NB_DRAW_THREADS - 1)
	{
		draw_thread_args[i].game = game;
		draw_thread_args[i].start = draw_thread_args[i - 1].end;
		draw_thread_args[i].end = (i + 1) * WIN_WIDTH / NB_DRAW_THREADS;
		i++;
	}
	if (NB_DRAW_THREADS == 1)
		return (true);
	draw_thread_args[NB_DRAW_THREADS - 1].game = game;
	draw_thread_args[NB_DRAW_THREADS - 1].start = \
		draw_thread_args[NB_DRAW_THREADS - 2].end;
	draw_thread_args[NB_DRAW_THREADS - 1].end = WIN_WIDTH;
	return (true);
}

static bool	t_game_init_params(t_game *game)
{
	game->frame_time_usec = 1000000 / FPS;
	game->tick_last_frame = 0;
	game->state = STATE_HOME;
	game->game_end_loop_count = 0;
	game->bullets = NULL;
	game->curr_map_index = NO_MAP_LOADED_INDEX;
	return (init_draw_thread_args(game, game->draw_thread_args));
}

/**
 * @brief Initializes the given t_game
 * @param game The structure to init
 * @return true on SUCCESS, false on ERROR
*/
bool	t_game_init(t_game *game)
{
	if (game == NULL)
		return (false);
	srand(time(NULL));
	return (
		t_game_init_params(game)
		&& t_mlx_init(&game->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE)
		&& init_game_uis(game, &game->uis)
		&& init_all_map_textures(game)
		&& t_mlx_launch(&game->mlx)
		&& add_event_handlers(game)
	);
}
