/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_neighboring_tiles_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:30:42 by brappo            #+#    #+#             */
/*   Updated: 2024/10/02 06:49:14 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pathfinding_bonus.h"
#include "map_bonus.h"
#include "utils_bonus.h"

/**
 * @param x neighbor x relative to pos
 * @param y neighbor y relative to pos
 * @return Return if the neighboring tile is walkable
 */
static bool	is_neighbor_valid(t_map *map, t_mlx_coords *pos, int x, int y)
{
	t_mlx_coords	neighbor_pos;

	neighbor_pos.x = pos->x + x;
	neighbor_pos.y = pos->y + y;
	return (is_walkable(map, &neighbor_pos));
}

/**
 * @brief Add a single tile to the stack if this coordinate is valid.
 */
static bool	add_neighbor(t_pathfinding *pathfinding, t_stack_path *top, \
	t_mlx_coords *relative_coords, t_map *map)
{
	int				distance;
	t_mlx_coords	neighbor_pos;

	if (relative_coords->x == 0 && relative_coords->y == 0)
		return (true);
	neighbor_pos.x = top->position.x + relative_coords->x;
	neighbor_pos.y = top->position.y + relative_coords->y;
	if (!is_walkable(map, &neighbor_pos)
		|| search_in_stack(pathfinding->locked_tiles, &neighbor_pos))
		return (true);
	if (relative_coords->x != 0 && relative_coords->y != 0)
	{
		distance = 14;
		if (!is_neighbor_valid(map, &top->position, relative_coords->x, 0)
			|| !is_neighbor_valid(map, &top->position, 0, relative_coords->y))
		{
			return (true);
		}
	}
	else
		distance = 10;
	return (add_path_node(&neighbor_pos, pathfinding, top, distance));
}

/**
 * @brief Add the neighboring tiles to the stack, sorted.
 */
bool	add_neighboring_tiles(t_pathfinding *pathfinding, t_map *map)
{
	t_mlx_coords	relative_coords;
	t_stack_path	*top;

	top = pathfinding->locked_tiles;
	relative_coords.y = -1;
	while (relative_coords.y < 2)
	{
		relative_coords.x = -1;
		while (relative_coords.x < 2)
		{
			if (!add_neighbor(pathfinding, top, &relative_coords, map))
				return (false);
			relative_coords.x++;
		}
		relative_coords.y++;
	}
	return (true);
}
