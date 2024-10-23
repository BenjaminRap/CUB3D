/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_entity_type_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:26:19 by brappo            #+#    #+#             */
/*   Updated: 2024/09/06 09:26:30 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities_bonus.h"

void	init_entity_type(t_entity *entity, char id, \
	t_animation anim[MAP_NB_IDS])
{
	static void	(*inits[12])(t_entity *, t_animation[MAP_NB_IDS]) = {
		demon_init, imp_init, caco_init, boh_init, lost_soul_init, \
	pain_elem_init, cyber_init, revenant_init, mancubus_init, commando_init, \
	sergeant_init};
	size_t		index;

	index = 0;
	while (index < 12)
	{
		if (id == IDS_MAP_ENTITY[index] || id == IDS_MAP_ENTITY[index] - 32)
			inits[index](entity, anim);
		index++;
	}
}
