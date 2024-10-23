/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lights_position_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 09:18:21 by brappo            #+#    #+#             */
/*   Updated: 2024/10/02 23:10:34 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_bonus.h"
#include "libft.h"
#include "lights_bonus.h"

/**
 * @brief Counts the number of light in this map.
 */
size_t	count_lights(t_map *map)
{
	size_t	y;
	size_t	x;
	size_t	lights_count;

	y = 0;
	lights_count = 0;
	while (y < map->lines_count)
	{
		x = 0 ;
		while (x < map->lines_lengths[y])
		{
			if (map->tiles[y][x] == ID_MAP_LIGHT
				|| map->tiles[y][x] == ID_MAP_LIGHT - 32)
			{
				lights_count++;
			}
			x++;
		}
		y++;
	}
	return (lights_count);
}

/**
 * @brief Set the lights coordinates
 * @param map The current selected map
 * @param light_count The number of lights
 * @param lights The array of lights whose coordinates will be set
 */
static void	find_lights(t_map *map, size_t light_count, t_light *lights)
{
	size_t		y;
	size_t		x;
	size_t		light_index;

	y = 0;
	light_index = 0;
	while (y < map->lines_count)
	{
		x = 0;
		while (x < map->lines_lengths[y])
		{
			if (map->tiles[y][x] == ID_MAP_LIGHT
				|| map->tiles[y][x] == ID_MAP_LIGHT - 32)
			{
				lights[light_index].position.y = (float)y + 0.5f;
				lights[light_index].position.x = (float)x + 0.5f;
				light_index++;
				if (light_index == light_count)
					return ;
			}
			x++;
		}
		y++;
	}
}

/**
 * @brief Allocate the map->lights variable and set the lights positions.
 * @return False if the allocation fail, true otherwise
 */
bool	get_lights_position(t_map *map, size_t lights_count)
{
	if (map == NULL)
		return (false);
	if (lights_count == 0)
		return (true);
	map->lights = ft_calloc(lights_count, sizeof(t_light));
	if (map->lights == NULL)
		return (false);
	find_lights(map, lights_count, map->lights);
	return (true);
}
