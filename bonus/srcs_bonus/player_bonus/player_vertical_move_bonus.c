/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_vertical_move_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:48:40 by brappo            #+#    #+#             */
/*   Updated: 2024/10/02 05:52:08 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_bonus.h"
#include "config_bonus.h"

/**
 * @brief camera_y is not useful for the rendering, only camera_y_diff, but
 * camera_y ismove conveniant for player movements so we set camera_y and call
 * get_camera_height_diff to translate our readable camera_y into the
 * usefulcamera_y_diff
 * @return If the player is just under the ceiling
 */
static bool	is_under_ceiling(t_player *player)
{
	return (player->camera_y >= WIN_HEIGHT - CEILING_MIN_DISTANCE);
}

/**
 * @brief Move the palyer by 'move' pixels
 * For the rendring to look consistant, we need to rotate it when changing the
 * camera height
 */
static void	move_vertically(t_player *player, float move)
{
	player->camera_y += move;
	player->camera_y_diff = get_camera_height_diff(player->camera_y);
	player->orientation.y += move;
}

bool	is_grounded(t_player *player)
{
	return (player->camera_y <= player->height + GROUND_MIN_DISTANCE);
}

/**
 * @param camera_height
 * @return The difference between the camera height and the middle of the screem
 */
float	get_camera_height_diff(float camera_height)
{
	return (WIN_HEIGHT / 2 - camera_height);
}

/**
 * @brief Apply the gravity or jump force on the player camera height
 */
void	apply_vertical_move(t_player *player, float delta_time)
{
	if (player->vertical_move == 0)
		return ;
	move_vertically(player, player->vertical_move * delta_time);
	if (
		(player->is_grounded && player->vertical_move < 0)
		|| (is_under_ceiling(player) && player->vertical_move > 0)
	)
		player->vertical_move = 0;
	if (!player->is_grounded)
		player->vertical_move -= player->gravity_force * delta_time;
}
