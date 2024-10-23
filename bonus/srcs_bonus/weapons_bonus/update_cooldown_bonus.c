/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_cooldown_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 23:14:47 by mhotting          #+#    #+#             */
/*   Updated: 2024/08/29 23:29:09 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "weapons_bonus.h"

void	weapon_update_cooldown(t_weapon *weapon, float delta_time)
{
	if (
		weapon == NULL || weapon->cooldown_effect == 0
		|| weapon->cooldown_curr == 0
	)
		return ;
	weapon->cooldown_curr -= delta_time;
	if (weapon->cooldown_curr < 0)
		weapon->cooldown_curr = 0;
}
