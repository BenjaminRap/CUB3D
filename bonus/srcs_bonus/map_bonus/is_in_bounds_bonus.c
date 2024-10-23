/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_bounds_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 00:54:27 by codekiwi          #+#    #+#             */
/*   Updated: 2024/10/02 05:36:49 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "map_bonus.h"
#include "vector_bonus.h"

bool	is_in_bounds(t_vector *position, t_map *map)
{
	if (position->x < 0
		|| position->y < 0
		|| position->y >= map->lines_count
		|| position->x >= map->lines_lengths[(int)floorf(position->y)])
		return (false);
	return (true);
}

bool	is_character(t_vector *position, t_map *map, char character)
{
	int	tile_x;
	int	tile_y;

	tile_x = position->x;
	tile_y = position->y;
	return (map->tiles[tile_y][tile_x] == character);
}

bool	is_walkable(t_map *map, t_mlx_coords *coords)
{
	if (coords->x < 0 || coords->y < 0
		|| (size_t)coords->y >= map->lines_count
		|| (size_t)coords->x >= map->lines_lengths[coords->y])
	{
		return (false);
	}
	return (map->tiles[coords->y][coords->x] != ID_MAP_WALL
			&& map->tiles[coords->y][coords->x] != ID_MAP_DOOR_CLOSED);
}
