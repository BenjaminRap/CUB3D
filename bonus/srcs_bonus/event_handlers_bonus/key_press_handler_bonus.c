/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_handler_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:16:10 by mhotting          #+#    #+#             */
/*   Updated: 2024/10/02 10:15:33 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "door_bonus.h"
#include "error_bonus.h"

/**
 * @brief Handles the keyboard press key events
 * @param game The t_game which contains project data to affect
 * @param key The integer value of the pressed key
 * @return A dummy integer
*/
int	key_press_handler(int key, t_game *game)
{
	t_player		*player;

	player = &game->player;
	if (game == NULL)
		return (0);
	if (game->state != STATE_PLAYING)
		return (0);
	else if (key == KEY_E)
		open_looked_door(player->look_ray, game->map);
	else if (key == KEY_SPACE && player->is_grounded)
		player->vertical_move = player->jump_force;
	else if (key == KEY_W)
		player->next_walk_direction[FRONT] = true;
	else if (key == KEY_S)
		player->next_walk_direction[BACK] = true;
	else if (key == KEY_A)
		player->next_walk_direction[LEFT] = true;
	else if (key == KEY_D)
		player->next_walk_direction[RIGHT] = true;
	else if (
		key >= FIRST_WEAPON_KEY && key <= LAST_WEAPON_KEY
		&& game->state != STATE_PLAYING
	)
		player_select_weapon(&player->weapon_info, key - FIRST_WEAPON_KEY);
	return (0);
}
