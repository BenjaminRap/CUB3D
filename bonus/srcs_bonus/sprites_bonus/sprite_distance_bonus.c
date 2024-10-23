/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_distance_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:42:11 by brappo            #+#    #+#             */
/*   Updated: 2024/10/02 04:48:58 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprite_bonus.h"
#include "libft.h"

void	get_sprites_distances(t_list *sprites, t_vector *pos)
{
	t_sprite	*sprite;

	while (sprites)
	{
		sprite = sprites->content;
		sprite->distance = get_distance(&sprite->position, pos);
		sprites = sprites->next;
	}
}

float	compare_sprite_distance(void *a, void *b)
{
	return (((t_sprite *)a)->distance - ((t_sprite *)b)->distance);
}
