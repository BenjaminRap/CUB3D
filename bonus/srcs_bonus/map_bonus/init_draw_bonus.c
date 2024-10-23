/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_draw_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:34:59 by codekiwi          #+#    #+#             */
/*   Updated: 2024/10/02 04:02:57 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "error_bonus.h"
#include "utils_bonus.h"

/**
 * @brief Returns the number of tiles of the longest line of the map
 * @param map the map whose maximum line length is evaluated
 * @return the maximum line length
 */
static int	get_map_max_line_len(t_map *map)
{
	size_t	i;
	size_t	max;

	i = 0;
	max = 0;
	while (i < map->lines_count)
	{
		if (map->lines_lengths[i] > max)
			max = map->lines_lengths[i];
		i++;
	}
	return (max);
}

/**
 * @brief Initializes the given t_map_draw member using map and game info
 * @param draw the t_map_draw element to initialize
 * @param map the game map
 * @param game the game global structure
 * @return true on SUCCESS, false on ERROR
 */
bool	init_map_draw(t_map_draw *draw, t_map *map, t_game *game)
{
	int	max_line_len;
	int	tile_size_vert;
	int	tile_size_horz;

	if (draw == NULL || map == NULL || game == NULL)
		return (error_print(ERR_MAP_DRAW_CREATION), false);
	max_line_len = (int) get_map_max_line_len(map);
	draw->size.x = (int)(MAP_DRAW_SIZE_RATIO * (float) game->mlx.width);
	draw->size.y = (int)(MAP_DRAW_SIZE_RATIO * (float) game->mlx.height);
	draw->nb_tiles.x = max_line_len;
	draw->nb_tiles.y = map->lines_count;
	tile_size_horz = draw->size.x / max_line_len;
	tile_size_vert = draw->size.y / map->lines_count;
	draw->tile_size = min(tile_size_horz, tile_size_vert);
	if (draw->tile_size < MAP_DRAW_MIN_TILE_SIZE)
		return (error_print(ERR_MAP_DRAW_SIZE), false);
	draw->size.x = draw->nb_tiles.x * draw->tile_size;
	draw->size.y = draw->nb_tiles.y * draw->tile_size;
	draw->coords.x = (game->mlx.width - draw->size.x) / 2;
	draw->coords.y = (game->mlx.height - draw->size.y) / 2;
	draw->element_radius = min(draw->tile_size / 6, MAP_DRAW_ELT_MAX_RADIUS);
	return (true);
}
