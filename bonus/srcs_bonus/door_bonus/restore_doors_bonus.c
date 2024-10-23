/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore_doors_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 04:41:37 by brappo            #+#    #+#             */
/*   Updated: 2024/09/11 04:45:22 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "door_bonus.h"

void	restore_doors(t_door *doors, size_t door_count)
{
	size_t	index;

	if (doors == NULL)
		return ;
	index = 0;
	while (index < door_count)
	{
		doors[index].state = CLOSED;
		doors[index].transition = 1;
		doors[index].time_since_opened = 0;
		index++;
	}
}
