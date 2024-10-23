/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 18:47:29 by mhotting          #+#    #+#             */
/*   Updated: 2024/08/27 14:05:00 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	draw_hud_health(t_game *game, t_hud *hud)
{
	t_mlx_coords	bar_size;

	t_mlx_draw_rect_texture(game->mlx.img_buff, &hud->health_lbl_pos, \
		&hud->health_lbl_size, hud->texture_lbl_health);
	t_mlx_draw_rectangle(game->mlx.img_buff, &hud->health_bar_pos, \
		&hud->health_bar_size, HUD_HEALTH_BAR_COL_BG);
	bar_size.x = ((float)game->player.health_point / PLAYER_HEALTH_POINT) \
		* hud->health_bar_size.x;
	bar_size.y = hud->health_bar_size.y;
	if (bar_size.x > 0)
		t_mlx_draw_rectangle(game->mlx.img_buff, &hud->health_bar_pos, \
			&bar_size, HUD_HEALTH_BAR_COL);
}

static void	draw_hud_weapon(t_game *game, t_hud *hud)
{
	t_mlx_coords	bar_size;

	t_mlx_draw_rect_texture(game->mlx.img_buff, &hud->weapon_lbl_pos, \
		&hud->weapon_lbl_size, hud->texture_lbl_weapon);
	t_mlx_draw_rectangle(game->mlx.img_buff, &hud->weapon_bar_pos, \
		&hud->weapon_bar_size, HUD_WEAPON_BAR_COL_BG);
	bar_size.x = ((float)game->player.weapon_info.curr_weapon->remaining_use \
		/ game->player.weapon_info.curr_weapon->load_capacity) \
		* hud->weapon_bar_size.x;
	bar_size.y = hud->weapon_bar_size.y;
	if (bar_size.x > 0)
		t_mlx_draw_rectangle(game->mlx.img_buff, &hud->weapon_bar_pos, \
			&bar_size, HUD_WEAPON_BAR_COL);
}

void	draw_hud(t_game *game, t_hud *hud)
{
	if (game == NULL || hud == NULL)
		return ;
	t_mlx_draw_rect_texture(game->mlx.img_buff, &hud->pos, &hud->size, \
		hud->texture_bg);
	draw_hud_health(game, hud);
	if (game->player.weapon_info.curr_weapon->is_limited)
		draw_hud_weapon(game, hud);
}
