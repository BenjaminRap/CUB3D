/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codekiwi <codekiwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:25:35 by brappo            #+#    #+#             */
/*   Updated: 2024/07/26 22:03:31 by codekiwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "cub3d.h"

static void	update_look(t_player *player)
{
	if (player->turn_direction[0] && !player->turn_direction[1])
		player->orientation += player->rotation_speed;
	else if (player->turn_direction[1] && !player->turn_direction[0])
		player->orientation -= player->rotation_speed;
}

static void	update_position(t_player *player, t_map *map)
{
	float		new_angle;
	t_vector	save_position;
	size_t		index;

	index = 0;
	while (index < 4)
	{
		if (player->walk_direction[index] != false
			&& player->walk_direction[(index + 2) % 4] == false)
		{
			save_position = player->position;
			new_angle = player->orientation + index * PI / 2;
			player->position.x += cos(new_angle) * player->move_speed[index];
			player->position.y -= sin(new_angle) * player->move_speed[index];
			if (is_wall(&player->position, map))
				player->position = save_position;
		}
		index++;
	}
}

void	update_player(t_player *player, t_map *map)
{
	update_look(player);
	update_position(player, map);
}
