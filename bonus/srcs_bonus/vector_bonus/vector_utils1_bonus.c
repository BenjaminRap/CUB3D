/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils1_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:42:24 by brappo            #+#    #+#             */
/*   Updated: 2024/10/02 06:24:30 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "vector_bonus.h"

void	t_vector_get_slope(t_vector *slope, float angle_rad)
{
	slope->x = cos(angle_rad);
	slope->y = sin(angle_rad);
}

float	get_distance(t_vector *a, t_vector *b)
{
	return (sqrtf((a->x - b->x) * (a->x - b->x) \
		+ (a->y - b->y) * (a->y - b->y)));
}

float	get_vector_length(t_vector *vector)
{
	return (sqrt(vector->x * vector->x + vector->y * vector->y));
}

void	mutlitply_vector(t_vector *vector, float factor)
{
	vector->x *= factor;
	vector->y *= factor;
}

void	add_vector(t_vector *src, t_vector *other)
{
	src->x += other->x;
	src->y += other->y;
}
