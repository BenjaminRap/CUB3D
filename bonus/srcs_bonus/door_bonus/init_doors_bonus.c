/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_doors_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 09:18:21 by brappo            #+#    #+#             */
/*   Updated: 2024/10/02 22:39:37 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "door_bonus.h"
#include "libft.h"
#include "cub3d_bonus.h"
#include "error_bonus.h"

static bool	is_door_valid(t_map *map, size_t x, size_t y)
{
	if (x == 0 || y == 0)
		return (false);
	if (x == map->lines_lengths[y] - 1 || y == map->lines_count - 1)
		return (false);
	if (map->tiles[y][x - 1] == '1' && map->tiles[y][x + 1] == '1')
		return (true);
	if (map->tiles[y - 1][x] == '1' && map->tiles[y + 1][x] == '1')
		return (true);
	return (false);
}

static ssize_t	count_doors(t_map *map)
{
	size_t	y;
	size_t	x;
	size_t	doors_count;

	y = 0;
	doors_count = 0;
	while (y < map->lines_count)
	{
		x = 0 ;
		while (x < map->lines_lengths[y])
		{
			if (map->tiles[y][x] == ID_MAP_DOOR_CLOSED
				|| map->tiles[y][x] == ID_MAP_DOOR_CLOSED - 32)
			{
				if (!is_door_valid(map, x, y))
					return (-1);
				doors_count++;
			}
			x++;
		}
		y++;
	}
	return (doors_count);
}

static void	init_door(t_door *door, size_t x, size_t y)
{
	door->position.x = x;
	door->position.y = y;
	door->state = CLOSED;
	door->transition = 1;
	door->time_since_opened = 0;
}

static void	find_doors(t_map *map, size_t door_count, t_door *doors)
{
	size_t		y;
	size_t		x;
	size_t		door_index;

	y = 0;
	door_index = 0;
	while (y < map->lines_count)
	{
		x = 0;
		while (x < map->lines_lengths[y])
		{
			if (map->tiles[y][x] == ID_MAP_DOOR_CLOSED
				|| map->tiles[y][x] == ID_MAP_DOOR_CLOSED - 32)
			{
				init_door(&doors[door_index], x, y);
				door_index++;
				if (door_index == door_count)
					return ;
			}
			x++;
		}
		y++;
	}
}

bool	init_doors(t_map *map)
{
	ssize_t	door_count;

	if (map == NULL)
		return (false);
	door_count = count_doors(map);
	if (door_count == -1)
	{
		error_print(INVALID_DOOR);
		return (false);
	}
	map->door_count = door_count;
	if (map->door_count != 0)
	{
		map->doors = ft_calloc(map->door_count, sizeof(t_door));
		if (map->doors == NULL)
			return (false);
		find_doors(map, map->door_count, map->doors);
	}
	else
		map->doors = NULL;
	return (true);
}
