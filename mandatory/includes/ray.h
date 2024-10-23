/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:57:08 by mhotting          #+#    #+#             */
/*   Updated: 2024/08/27 15:46:01 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include <stdbool.h>
# include "vector.h"

typedef struct s_ray	t_ray;
typedef struct s_player	t_player;
typedef struct s_map	t_map;

struct s_ray
{
	float		angle_from_orientation;
	float		length;
	t_vector	intersection;
	bool		is_vertical;
	t_vector	slope;
};

// Raycasting functions
float	raycast(t_vector position, t_vector *slope, t_map *map,
			bool *is_vertical);
void	cast_rays(t_player *player, t_map *map, t_ray *rays);

#endif