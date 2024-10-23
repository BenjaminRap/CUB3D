/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_lights_values_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 03:47:27 by brappo            #+#    #+#             */
/*   Updated: 2024/09/16 14:12:27 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "lights_bonus.h"
#include "libft.h"

/**
 * @brief Check if a ray of the lights intersect something
 * @return True if at least one ray intersect
 */
static bool	intersect_with_wall(float *rays_distances, size_t ray_count)
{
	size_t	index;
	float	ray_max_distance;

	index = 0;
	ray_max_distance = LIGHT_SQUARED_DISTANCE - LIGHT_ACCEPTED_ERROR;
	while (index < ray_count)
	{
		if (rays_distances[index] < ray_max_distance)
			return (true);
		index++;
	}
	return (false);
}

/**
 * @brief raycast in all direction, ray_count times and set the resut in
 * light->rays. The rays will be uniformely distributed in all direction.
 * @return False if the allocation fail, true otherwise
 */
static bool	cast_light_rays(t_game *game, t_light *light, size_t ray_count)
{
	size_t	index;
	float	angle;
	float	angle_by_unit;
	t_ray	ray;

	light->rays = ft_calloc(ray_count, sizeof(float));
	if (light->rays == NULL)
		return (false);
	index = 0;
	angle = 0.0f;
	angle_by_unit = 2 * PI / (ray_count - 1);
	while (index < ray_count)
	{
		t_vector_get_slope(&ray.slope, angle);
		light->rays[index] = raycast(light->position, game, &ray, \
			LIGHT_DISTANCE);
		light->rays[index] *= light->rays[index];
		angle += angle_by_unit;
		index++;
	}
	return (true);
}

/**
 * @brief cast the rays of all lights.If a lights doesn't intersect with
 * anything, set rays to NULL
 * @return False if an allocation failed or game is NULL, true otherwise
 */
bool	set_lights_values(t_game *game)
{
	size_t	index;
	t_map	*map;
	size_t	ray_count;
	t_light	*light;

	index = 0;
	if (game == NULL)
		return (false);
	map = game->map;
	ray_count = 2 * PI * LIGHT_RAY_BY_ANGLE + 1;
	while (index < map->lights_count)
	{
		light = &map->lights[index];
		if (!cast_light_rays(game, light, ray_count))
			return (false);
		if (!intersect_with_wall(light->rays, ray_count))
		{
			free(light->rays);
			light->rays = NULL;
		}
		index++;
	}
	return (true);
}
