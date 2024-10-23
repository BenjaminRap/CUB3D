/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:01:34 by root              #+#    #+#             */
/*   Updated: 2024/10/02 22:41:11 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "cub3d_bonus.h"
#include "utils_bonus.h"

/**
 * @brief set the size of a segment of slope, when x is 1 or y is 1
 * @param slope The slope of the vector
 */
static void	calculate_unit_length(t_raycast *ray_x, t_raycast *ray_y,
	t_vector *slope)
{
	ray_x->unit_length = sqrt(1 + pow((slope->y / slope->x), 2));
	ray_y->unit_length = sqrt(1 + pow((slope->x / slope->y), 2));
}

static void	calculate_inital_sum(t_raycast *ray_x, t_raycast *ray_y,
	t_vector *slope, t_vector *position)
{
	if (slope->x < 0)
		ray_x->sum_length = modff(position->x, &position->x);
	else
		ray_x->sum_length = 1 - modff(position->x, &position->x);
	if (slope->y < 0)
		ray_y->sum_length = 1 - modff(position->y, &position->y);
	else
		ray_y->sum_length = modff(position->y, &position->y);
	ray_x->sum_length *= ray_x->unit_length;
	ray_y->sum_length *= ray_y->unit_length;
}

float	raycast_progress(t_raycast *raycast, t_game *game, t_vector *position,
	t_ray *ray)
{
	*raycast->position += raycast->sign;
	if (!is_in_bounds(position, game->map)
		|| is_character(position, game->map, ID_MAP_WALL))
	{
		ray->is_vertical = raycast->is_vertical;
		return (raycast->sum_length);
	}
	if (game->map->door_count > 0 && is_door(position, game, ray, raycast))
	{
		ray->is_vertical = raycast->is_vertical;
		ray->is_door = true;
		return (raycast->sum_length + raycast->unit_length / 2);
	}
	raycast->sum_length += raycast->unit_length;
	return (-1);
}

/**
 * @brief Cast a ray and return the distance of the wall hit
 * @param position The player position
 * @param max_distance The max distance a ray can travel
 * @note This function also set the is_door and is_vertical values
 */
float	raycast(t_vector position, t_game *game, t_ray *ray, int max_distance)
{
	t_raycast	ray_x;
	t_raycast	ray_y;
	float		length;

	ray_x.sign = sign(ray->slope.x);
	ray_y.sign = -sign(ray->slope.y);
	ray_x.is_vertical = true;
	ray_y.is_vertical = false;
	ray_x.position = &position.x;
	ray_y.position = &position.y;
	calculate_unit_length(&ray_x, &ray_y, &ray->slope);
	calculate_inital_sum(&ray_x, &ray_y, &ray->slope, &position);
	while (ray_x.sum_length < max_distance || ray_y.sum_length < max_distance)
	{
		if (ray_x.sum_length <= ray_y.sum_length)
			length = raycast_progress(&ray_x, game, &position, ray);
		else
			length = raycast_progress(&ray_y, game, &position, ray);
		if (length != -1)
			return (length);
	}
	return (max_distance);
}
