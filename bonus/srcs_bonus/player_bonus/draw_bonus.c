/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:57:37 by mhotting          #+#    #+#             */
/*   Updated: 2024/08/27 14:17:18 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	draw_player(t_game *game, t_player_weapon *weapon_info)
{
	t_weapon		*weapon;
	t_mlx_coords	coords;

	if (game == NULL || weapon_info == NULL || weapon_info->curr_weapon == NULL)
		return ;
	weapon = weapon_info->curr_weapon;
	coords.x = weapon->coords.x + weapon_info->draw_offset.x;
	coords.y = weapon->coords.y + weapon_info->draw_offset.y;
	t_mlx_draw_rect_texture(game->mlx.img_buff, &coords, &weapon->size, \
		weapon->curr_frame);
	if (weapon_info->curr_weapon->target != NULL)
		t_mlx_draw_rect_texture(game->mlx.img_buff, &weapon->target_coords, \
			&weapon->target_size, weapon->target);
}
