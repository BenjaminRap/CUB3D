/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lights_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 04:15:24 by brappo            #+#    #+#             */
/*   Updated: 2024/10/02 23:00:14 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "libft.h"
#include "lights_bonus.h"

/**
 * @brief Free the rays of the lights and set lights to NULL
 * @param lightsPointer A pointer on the array of lights
 * @param lights_count The length of the array
 */
void	free_lights(t_light **lightsPointer, size_t lights_count)
{
	size_t	index;
	t_light	*lights;

	index = 0;
	if (lightsPointer == NULL)
		return ;
	lights = *lightsPointer;
	if (lights == NULL)
		return ;
	while (index < lights_count)
	{
		if (lights[index].rays != NULL)
			free(lights[index].rays);
		index++;
	}
	free(lights);
	*lightsPointer = NULL;
}

/**
 * @brief Cast the rays of the lights of the current selected map in game.
 * @return False if this function failed to allocate the rays or if game or map
 * are NULL, true otherwise
 */
bool	init_lights(t_game *game)
{
	t_map		*map;

	if (game == NULL || game->map == NULL)
		return (false);
	map = game->map;
	map->lights_count = count_lights(map);
	if (map->lights_count == 0)
		return (true);
	if (!get_lights_position(map, map->lights_count))
		return (false);
	if (!set_lights_values(game))
	{
		free_lights(&map->lights, map->lights_count);
		return (false);
	}
	return (true);
}
