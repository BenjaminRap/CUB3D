/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_pause_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 07:19:29 by codekiwi          #+#    #+#             */
/*   Updated: 2024/09/05 16:32:19 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	game_pause_switch(t_game *game)
{
	if (game == NULL)
		return ;
	if (game->state == STATE_PAUSE)
		game->state = STATE_PLAYING;
	else
		game->state = STATE_PAUSE;
	if (game->state == STATE_PAUSE)
	{
		t_image_multiply_each_px(game->mlx.img_buff, PAUSE_BG_DARK_FACTOR);
		t_mlx_mouse_show(&game->mlx, &game->mouse_hidden);
		t_mlx_sync_images(&game->mlx);
	}
	else
		game_pause_close(game);
}

void	game_pause_close(t_game *game)
{
	if (game == NULL)
		return ;
	game->state = STATE_PLAYING;
	disable_buttons_ui(&game->uis.pause);
	t_mlx_mouse_hide(&game->mlx, &game->mouse_hidden);
}
