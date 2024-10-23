/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_positions_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:32:58 by mhotting          #+#    #+#             */
/*   Updated: 2024/08/27 14:25:34 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "weapons_bonus.h"

void	set_weapon_position(t_weapon *weapon, t_mlx *mlx)
{
	if (mlx == NULL || weapon == NULL)
		return ;
	weapon->coords.x = (mlx->width - weapon->curr_frame->width) / 2;
	weapon->coords.y = mlx->height - weapon->curr_frame->height;
	weapon->size.x = weapon->curr_frame->width;
	weapon->size.y = weapon->curr_frame->height;
}

void	set_weapon_target_position(t_weapon *weapon, t_mlx *mlx)
{
	if (mlx == NULL || weapon == NULL)
		return ;
	if (weapon->target == NULL)
	{
		weapon->target_coords.x = 0;
		weapon->target_coords.y = 0;
		weapon->target_size.x = 0;
		weapon->target_size.y = 0;
		return ;
	}
	weapon->target_coords.x = (mlx->width - weapon->target->width) / 2;
	weapon->target_coords.y = (mlx->height - weapon->target->height) / 2;
	weapon->target_size.x = weapon->target->width;
	weapon->target_size.y = weapon->target->height;
}

void	init_all_weapon_positions(t_weapon weapons[NB_TOT_WEAPONS], t_mlx *mlx)
{
	size_t	i;

	if (weapons == NULL || mlx == NULL)
		return ;
	i = 0;
	while (i < NB_TOT_WEAPONS)
	{
		set_weapon_position(&weapons[i], mlx);
		set_weapon_target_position(&weapons[i], mlx);
		i++;
	}
}
