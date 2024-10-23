/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:01:34 by root              #+#    #+#             */
/*   Updated: 2024/08/27 14:36:12 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "cub3d.h"

static void	calculate_unit_length(t_vector *unit_length, t_vector *slope)
{
	unit_length->x = sqrt(1 + pow((slope->y / slope->x), 2));
	unit_length->y = sqrt(1 + pow((slope->x / slope->y), 2));
}

static void	calculate_inital_sum(t_vector *sum_length, t_vector *unit_length,
	t_vector *position, t_vector *slope)
{
	if (slope->x < 0)
		sum_length->x = modff(position->x, &position->x);
	else
		sum_length->x = 1 - modff(position->x, &position->x);
	if (slope->y < 0)
		sum_length->y = 1 - modff(position->y, &position->y);
	else
		sum_length->y = modff(position->y, &position->y);
	sum_length->x *= unit_length->x;
	sum_length->y *= unit_length->y;
}

float	raycast(t_vector position, t_vector *slope, t_map *map,
	bool *is_vertical)
{
	t_vector	unit_length;
	t_vector	sum_length;

	calculate_unit_length(&unit_length, slope);
	calculate_inital_sum(&sum_length, &unit_length, &position, slope);
	while (sum_length.x < MAX_DISTANCE || sum_length.y < MAX_DISTANCE)
	{
		if (sum_length.x <= sum_length.y)
		{
			position.x += sign(slope->x);
			if (is_wall(&position, map))
				return (*is_vertical = true, sum_length.x);
			sum_length.x += unit_length.x;
		}
		else
		{
			position.y -= sign(slope->y);
			if (is_wall(&position, map))
				return (*is_vertical = false, sum_length.y);
			sum_length.y += unit_length.y;
		}
	}
	return (MAX_DISTANCE);
}
