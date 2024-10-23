/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move_handler_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 20:35:15 by codekiwi          #+#    #+#             */
/*   Updated: 2024/10/02 10:16:04 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "event_handlers_bonus.h"

static void	mouse_move_buttons_handler(int x, int y, t_game *game, t_ui *ui)
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
			lvl_btn->texture_active = lvl_btn->texture_on;
		else
			lvl_btn->texture_active = lvl_btn->texture_off;
		i++;
	}
}

int	mouse_move_handler(int x, int y, t_game *game)
{
	int			x_delta;
	int			y_delta;
	t_player	*player;

	if (game == NULL)
		return (0);
	if (game->state == STATE_GAMEOVER)
		mouse_move_buttons_handler(x, y, game, &game->uis.game_over);
	else if (game->state == STATE_GAMEWIN)
		mouse_move_buttons_handler(x, y, game, &game->uis.win);
	else if (game->state == STATE_PAUSE)
		mouse_move_buttons_handler(x, y, game, &game->uis.pause);
	else if (game->state == STATE_HOME)
		mouse_move_buttons_handler(x, y, game, &game->uis.home);
	else if (game->state == STATE_LEVEL_SELECTION)
		mouse_move_buttons_handler(x, y, game, &game->uis.level_selection);
	else
	{
		player = &game->player;
		x_delta = game->mlx.width_half - x;
		y_delta = game->mlx.height_half - y;
		player->rotation_speed.x = (float)x_delta * MOTION_X_FACTOR;
		player->rotation_speed.y = (float)y_delta * MOTION_Y_FACTOR;
	}
	return (1);
}
