/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_get_damage_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:10:51 by brappo            #+#    #+#             */
/*   Updated: 2024/08/26 12:19:39 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	player_get_damage(t_game *game, size_t damage)
{
	t_player	*player;

	player = &game->player;
	if (player->health_point > damage)
		player->health_point -= damage;
	else
	{
		player->health_point = 0;
		player->is_dead = true;
	}
}
