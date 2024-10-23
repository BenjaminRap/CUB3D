/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_luminosity_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 09:27:48 by brappo            #+#    #+#             */
/*   Updated: 2024/10/02 23:11:14 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lights_bonus.h"
#include "map_bonus.h"
#include "config_bonus.h"

#include <math.h>

/**
 * @brief Return the angle between the x axis of the light, and the position
 * @return An angle in range [0, 2 * PI]
 */
static float	get_position_angle(t_vector *light_pos, t_vector *position)
{
	float		position_angle;
	t_vector	light_to_pos;

	light_to_pos.x = position->x - light_pos->x;
	light_to_pos.y = light_pos->y - position->y;
	position_angle = atan2(light_to_pos.y, light_to_pos.x);
	if (position_angle < 0)
		position_angle += 2 * PI;
	else if (position_angle > 2 * PI)
		position_angle -= 2 * PI;
	return (position_angle);
}

/**
 * @brief Return the luminosity caused by this light. If the rays are NULL, it
 * means that the light intersect with nothing, in this case, we only check the
 * distance.
 */
static float	get_light_luminosity(t_light *light, t_vector *position)
{
	float		position_angle;
	float		squared_distance;
	size_t		ray_index;

	squared_distance = get_squared_distance(&light->position, position);
	if (squared_distance > LIGHT_SQUARED_DISTANCE)
		return (0.0f);
	if (light->rays != NULL)
	{
		position_angle = get_position_angle(&light->position, position);
		ray_index = position_angle * LIGHT_RAY_BY_ANGLE;
		if (light->rays[ray_index] + LIGHT_ACCEPTED_ERROR < squared_distance)
			return (0.0f);
	}
	return (1.0f - squared_distance / LIGHT_SQUARED_DISTANCE);
}

/**
 * @brief Calculate the luminosty at position, checking all the lights of map
 * @param position The coordinates of the pixel we want the luminosity
 * @param map The current selected map
 * @param inv_dist The inverse distance to the player
 * @return The luminosity in range [0.0f,1.0f]
 */
float	get_luminosity(t_vector *position, t_map *map, float inv_dist)
{
	float	luminosity;
	float	distance_factor;
	size_t	index;

	luminosity = DEFAULT_LUMINOSITY;
	index = 0;
	distance_factor = 1 - 1 / (inv_dist * MAX_VISION_DISTANCE);
	while (index < map->lights_count)
	{
		luminosity += get_light_luminosity(&map->lights[index], position);
		if (luminosity >= 1.0f)
			return (1.0f * distance_factor);
		index++;
	}
	return (luminosity * distance_factor);
}
