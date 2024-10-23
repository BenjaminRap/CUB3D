/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:46:33 by mhotting          #+#    #+#             */
/*   Updated: 2024/08/26 10:45:04 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUD_BONUS_H
# define HUD_BONUS_H

# include "mlx_api_bonus.h"

# define HUD_W_RATIO			0.25f
# define HUD_H_RATIO			0.25f
# define HUD_LABEL_H_RATIO		0.2f
# define HUD_LABEL_W_RATIO		0.3f
# define HUD_BAR_H_RATIO		0.2f
# define HUD_BAR_W_RATIO		0.6f
# define HUD_HEALTH_BAR_COL		0xC70404
# define HUD_HEALTH_BAR_COL_BG	0x570101
# define HUD_WEAPON_BAR_COL		0x0593F2
# define HUD_WEAPON_BAR_COL_BG	0x002945

typedef struct s_hud	t_hud;
typedef struct s_game	t_game;

struct s_hud
{
	t_mlx_coords	pos;
	t_mlx_coords	size;
	t_mlx_coords	health_lbl_size;
	t_mlx_coords	health_lbl_pos;
	t_mlx_coords	health_bar_size;
	t_mlx_coords	health_bar_pos;
	t_mlx_coords	weapon_lbl_size;
	t_mlx_coords	weapon_lbl_pos;
	t_mlx_coords	weapon_bar_size;
	t_mlx_coords	weapon_bar_pos;
	t_image			*texture_bg;
	t_image			*texture_lbl_health;
	t_image			*texture_lbl_weapon;
};

// HUD functions
bool	init_hud(t_game *game, t_hud *hud);
void	draw_hud(t_game *game, t_hud *hud);

#endif
