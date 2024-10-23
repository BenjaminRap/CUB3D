/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 04:14:23 by brappo            #+#    #+#             */
/*   Updated: 2024/10/02 22:56:29 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHTS_BONUS_H
# define LIGHTS_BONUS_H

// LIGHT_DISTANCE but squared, usefull for more efficient calculations
# define LIGHT_SQUARED_DISTANCE	25.0f
// The range of a light
# define LIGHT_DISTANCE			5.0f
// The luminosity of a pixel without light
# define DEFAULT_LUMINOSITY		0.2f
// Rays count = 2 * PI * LIGHT_RAY_BY_ANGLE, the angle is in radian
// Increasing this increase the allocation and the precision
# define LIGHT_RAY_BY_ANGLE		2000
// Increasing this decreased the black bands but increase the lights precision
//error in corners
# define LIGHT_ACCEPTED_ERROR	0.285f
# include "vector_bonus.h"

# include <stddef.h>
# include <stdbool.h>

typedef struct s_map	t_map;
typedef struct s_game	t_game;
typedef struct s_light	t_light;

struct	s_light
{
	t_vector	position;
	float		*rays;
};

bool	get_lights_position(t_map *map, size_t lights_count);
size_t	count_lights(t_map *map);
bool	init_lights(t_game *game);
float	get_luminosity(t_vector *position, t_map *map, float distance);
bool	set_lights_values(t_game *game);
void	free_lights(t_light **lightsPointer, size_t lights_count);

#endif // !LIGHTS_BONUS_H