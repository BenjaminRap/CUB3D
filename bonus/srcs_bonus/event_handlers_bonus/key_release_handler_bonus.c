/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release_handler_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:15:55 by mhotting          #+#    #+#             */
/*   Updated: 2024/10/02 10:15:30 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "error_bonus.h"

/**
 * @brief Handles the keyboard release key events
 * @param game The t_game which contains project data to affect
 * @param key The integer value of the pressed key
 * @return A dummy integer
*/
int	key_release_handler(int key, t_game *game)
{
	if (game == NULL)
		return (0);
	if (game->state != STATE_PLAYING && game->state != STATE_PAUSE)
		return (0);
	else if (game->state == STATE_PLAYING && key == KEY_W)
		game->player.next_walk_direction[FRONT] = false;
	else if (game->state == STATE_PLAYING && key == KEY_S)
		game->player.next_walk_direction[BACK] = false;
	else if (game->state == STATE_PLAYING && key == KEY_A)
		game->player.next_walk_direction[LEFT] = false;
	else if (game->state == STATE_PLAYING && key == KEY_D)
		game->player.next_walk_direction[RIGHT] = false;
	else if (game->state == STATE_PLAYING && key == KEY_M)
		game->map_opened = !game->map_opened;
	else if (key == KEY_ESC)
		game_pause_switch(game);
	return (0);
}
