/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:57:08 by mhotting          #+#    #+#             */
/*   Updated: 2024/09/04 09:35:11 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_BONUS_H
# define RAY_BONUS_H

# include <stdbool.h>
# include "vector_bonus.h"

typedef struct s_ray		t_ray;
typedef struct s_player		t_player;
typedef struct s_map		t_map;
typedef struct s_door		t_door;
typedef struct s_raycasting	t_raycasting;
typedef struct s_raycast	t_raycast;
typedef enum e_door_state	t_door_state;

struct s_ray
{
	float		angle_from_orientation;
	float		length;
	t_vector	intersection;
	bool		is_vertical;
	t_vector	slope;
	float		cos_angle;
	bool		is_door;
	t_door		*door;
};

struct s_raycast
{
	float	unit_length;
	float	sum_length;
	int		sign;
	float	*position;
	bool	is_vertical;
};

// Raycasting functions
float	raycast(t_vector position, t_game *game, t_ray *ray,
			int max_distance);
void	cast_rays(t_game *game);
bool	is_door(t_vector *pos, t_game *game, t_ray *ray,
			t_raycast *raycast);

#endif
