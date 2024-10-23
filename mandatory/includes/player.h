/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codekiwi <codekiwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:04:34 by mhotting          #+#    #+#             */
/*   Updated: 2024/07/26 22:03:31 by codekiwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "vector.h"

# define PLAYER_POS_ORDERED	"ENWS"
# define FOV_ANGLE_DEFAULT	1.047197551 
# define FRONT 				0
# define LEFT 				1
# define BACK 				2
# define RIGHT 				3

typedef struct s_player	t_player;

struct s_player
{
	float		fov_angle;
	t_vector	position;
	float		orientation;
	bool		walk_direction[4];
	int			turn_direction[2];
	float		move_speed[4];
	float		rotation_speed;
};

// t_player functions
bool	t_player_init(t_player *player, t_map *map);

void	update_player(t_player *player, t_map *map);

#endif