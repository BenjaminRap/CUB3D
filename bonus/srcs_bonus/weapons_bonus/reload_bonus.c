/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reload_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 14:00:17 by mhotting          #+#    #+#             */
/*   Updated: 2024/10/02 06:28:11 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "weapons_bonus.h"
#include "utils_bonus.h"

static void	reaload_weapon(t_weapon *weapon, float reload_ratio)
{
	int	reload_size;

	if (weapon == NULL)
		return ;
	reload_size = reload_ratio * weapon->load_capacity;
	if (reload_size == 0)
		reload_size = 1;
	weapon->remaining_use = \
		min(weapon->load_capacity, weapon->remaining_use + reload_size);
}

void	reload_weapons_randomly(
	t_weapon weapons[NB_TOT_WEAPONS],
	float reload_ratio,
	float reload_probability
)
{
	size_t	i;

	if (weapons == NULL || reload_ratio == 0 || reload_probability == 0)
		return ;
	i = 0;
	while (i < NB_TOT_WEAPONS)
	{
		if (get_random_bool(reload_probability))
			reaload_weapon(&weapons[i], reload_ratio);
		i++;
	}
}
