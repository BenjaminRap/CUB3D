/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_release_handler_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 20:35:11 by codekiwi          #+#    #+#             */
/*   Updated: 2024/10/02 10:15:06 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	mouse_release_buttons_handler(int x, int y, t_game *game, t_ui *ui)
{
	t_button	*lvl_btn;
	size_t		i;

	if (game == NULL || ui == NULL)
		return ;
	i = 0;
	while (i < ui->nb_buttons)
	{
		lvl_btn = &ui->buttons[i];
		if (is_over_button(lvl_btn, x, y))
		{
			lvl_btn->callback((void *)game);
			break ;
		}
		i++;
	}
}

int	mouse_release_handler(int button, int x, int y, t_game *game)
{
	if (game == NULL)
		return (0);
	if (button == MOUSE_LEFT && game->state == STATE_PAUSE)
		mouse_release_buttons_handler(x, y, game, &game->uis.pause);
	else if (button == MOUSE_LEFT && game->state == STATE_GAMEOVER)
		mouse_release_buttons_handler(x, y, game, &game->uis.game_over);
	else if (button == MOUSE_LEFT && game->state == STATE_GAMEWIN)
		mouse_release_buttons_handler(x, y, game, &game->uis.win);
	else if (button == MOUSE_LEFT && game->state == STATE_HOME)
		mouse_release_buttons_handler(x, y, game, &game->uis.home);
	else if (button == MOUSE_LEFT && game->state == STATE_LEVEL_SELECTION)
		mouse_release_buttons_handler(x, y, game, &game->uis.level_selection);
	else if (button == MOUSE_LEFT)
		player_weapon_use_stop(&game->player.weapon_info, game);
	return (1);
}
