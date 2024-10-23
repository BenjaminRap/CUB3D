/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:31:20 by mhotting          #+#    #+#             */
/*   Updated: 2024/08/30 23:55:15 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "libft.h"

void	update_weapon(t_weapon *weapon, t_game *game)
{
	if (weapon->curr_frame_link != NULL)
	{
		weapon->curr_frame_link = weapon->curr_frame_link->next;
		if (weapon->curr_frame_link != NULL)
			weapon->curr_frame = (t_image *) weapon->curr_frame_link->content;
		else
		{
			if (
				weapon->is_use_continuous && weapon->using \
				&& (weapon->remaining_use > 0 || !weapon->is_limited)
			)
				use_weapon(weapon, game);
			else
			{
				stop_weapon(weapon);
				weapon->curr_frame = weapon->frame_default;
				set_weapon_position(weapon, &game->mlx);
			}
		}
	}
}
