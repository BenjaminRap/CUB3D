/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 18:47:38 by mhotting          #+#    #+#             */
/*   Updated: 2024/10/02 04:06:44 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "libft.h"
#include "utils_bonus.h"

static void	init_hud_sizes(t_game *game, t_hud *hud)
{
	hud->size.x = HUD_W_RATIO * game->mlx.width;
	hud->size.y = HUD_H_RATIO * game->mlx.height;
	hud->health_lbl_size.y = HUD_LABEL_H_RATIO * hud->size.y;
	hud->health_lbl_size.x = hud->health_lbl_size.y;
	hud->health_bar_size.x = HUD_BAR_W_RATIO * hud->size.x;
	hud->health_bar_size.y = HUD_BAR_H_RATIO * hud->size.y;
	hud->weapon_lbl_size.x = hud->health_lbl_size.x;
	hud->weapon_lbl_size.y = hud->health_lbl_size.y;
	hud->weapon_bar_size.x = hud->health_bar_size.x;
	hud->weapon_bar_size.y = hud->health_bar_size.y;
}

static void	init_hud_positions(t_game *game, t_hud *hud)
{
	int	x_margin;
	int	y_margin;
	int	health_area_height;

	health_area_height = \
		max_int(hud->health_bar_size.y, hud->health_lbl_size.y);
	x_margin = \
		(hud->size.x - hud->health_lbl_size.x - hud->health_bar_size.x) / 3;
	y_margin = (hud->size.y - 2 * health_area_height) / 3;
	hud->pos.x = game->mlx.width - hud->size.x;
	hud->pos.y = game->mlx.height - hud->size.y;
	hud->health_lbl_pos.x = hud->pos.x + x_margin;
	hud->health_lbl_pos.y = hud->pos.y + y_margin;
	hud->health_bar_pos.x = hud->pos.x + hud->health_lbl_size.x + 2 * x_margin;
	hud->health_bar_pos.y = hud->health_lbl_pos.y;
	hud->weapon_lbl_pos.x = hud->health_lbl_pos.x;
	hud->weapon_lbl_pos.y = hud->pos.y + health_area_height + 2 * y_margin;
	hud->weapon_bar_pos.x = hud->health_bar_pos.x;
	hud->weapon_bar_pos.y = hud->weapon_lbl_pos.y;
}

static bool	init_hud_textures(t_game *game, t_hud *hud)
{
	hud->texture_bg = game->anim[IDX_TXTR_HUD_BG].textures->content;
	hud->texture_lbl_health = \
		game->anim[IDX_TXTR_HUD_HEALTH_LBL].textures->content;
	hud->texture_lbl_weapon = \
		game->anim[IDX_TXTR_HUD_WEAPON_LBL].textures->content;
	if (
		!t_image_resize(game->mlx.mlx_ptr, hud->texture_bg, &hud->size)
		|| !t_image_resize(game->mlx.mlx_ptr, hud->texture_lbl_health, \
			&hud->health_lbl_size)
		|| !t_image_resize(game->mlx.mlx_ptr, hud->texture_lbl_weapon, \
			&hud->weapon_lbl_size)
	)
		return (false);
	return (true);
}

bool	init_hud(t_game *game, t_hud *hud)
{
	if (game == NULL || hud == NULL)
		return (false);
	init_hud_sizes(game, hud);
	init_hud_positions(game, hud);
	return (init_hud_textures(game, hud));
}
