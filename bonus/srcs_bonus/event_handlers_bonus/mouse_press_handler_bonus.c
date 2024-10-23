/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_press_handler_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 20:35:11 by codekiwi          #+#    #+#             */
/*   Updated: 2024/10/02 10:15:11 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "error_bonus.h"

int	mouse_press_handler(int button, int x, int y, t_game *game)
{
	t_player_weapon	*weapon_info;

	(void) x;
	(void) y;
	weapon_info = &game->player.weapon_info;
	if (game == NULL)
		return (0);
	if (game->state != STATE_PLAYING)
		return (0);
	if (button == MOUSE_LEFT)
		player_weapon_use(&game->player.weapon_info, game);
	else if (button == MOUSE_WHEEL_DOWN)
		player_select_weapon(weapon_info, weapon_info->curr_weapon_index + 1);
	else if (button == MOUSE_WHEEL_UP)
		player_select_weapon(weapon_info, weapon_info->curr_weapon_index - 1);
	return (1);
}
