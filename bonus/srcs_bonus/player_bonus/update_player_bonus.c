/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:25:35 by brappo            #+#    #+#             */
/*   Updated: 2024/10/02 05:53:28 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "cub3d_bonus.h"
#include "libft.h"

static bool	is_walking(t_player *player)
{
	return (
		(player->walk_direction[FRONT] && !player->walk_direction[BACK])
		|| (player->walk_direction[BACK] && !player->walk_direction[FRONT])
		|| (player->walk_direction[LEFT] && !player->walk_direction[RIGHT])
		|| (player->walk_direction[RIGHT] && !player->walk_direction[LEFT])
	);
}

static bool	can_rotate(float new_y_rot, float rotation)
{
	if (new_y_rot < MAX_Y_ROTATION_RATIO * WIN_HEIGHT && rotation > 0)
		return (true);
	if (new_y_rot > -MAX_Y_ROTATION_RATIO * WIN_HEIGHT && rotation < 0)
		return (true);
	return (false);
}

static void	update_look(t_player *player, float delta_time)
{
	float	new_y_rot;

	if (player->rotation_speed.x != 0.0f)
	{
		player->orientation.x += player->rotation_speed.x * delta_time;
		player->rotation_speed.x = 0.0f;
	}
	if (player->orientation.x > 2 * PI)
		player->orientation.x -= 2 * PI;
	else if (player->orientation.x < 0)
		player->orientation.x += 2 * PI;
	new_y_rot = player->orientation.y + player->rotation_speed.y * delta_time;
	if (player->rotation_speed.y != 0.0f
		&& can_rotate(new_y_rot, player->rotation_speed.y))
	{
		player->orientation.y = new_y_rot;
		player->rotation_speed.y = 0.0f;
	}
}

static void	update_position(t_player *player, t_map *map, float delta_time,
	t_list *entities)
{
	float			new_angle;
	t_vector		move;
	size_t			index;

	index = 0;
	if (player->is_grounded)
	{
		ft_memcpy(player->walk_direction, player->next_walk_direction, \
			4 * sizeof(bool));
	}
	while (index < 4)
	{
		if (player->walk_direction[index] != false
			&& player->walk_direction[(index + 2) % 4] == false)
		{
			new_angle = player->orientation.x + index * PI / 2;
			move.x = cos(new_angle) * player->move_speed[index] * delta_time;
			move.y = -sin(new_angle) * player->move_speed[index] * delta_time;
			move_player(entities, &player->position, &move, map);
		}
		index++;
	}
}

void	update_player(t_game *game, float delta_time)
{
	t_player	*player;

	if (game == NULL)
		return ;
	player = &game->player;
	player->is_walking = is_walking(player);
	player->is_grounded = is_grounded(player);
	update_look(player, delta_time);
	apply_vertical_move(player, delta_time);
	update_position(player, game->map, delta_time, game->entities);
	update_player_weapon(&player->weapon_info, player->is_walking, \
		game, delta_time);
}
