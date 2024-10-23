/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_entities_position_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:41:57 by brappo            #+#    #+#             */
/*   Updated: 2024/10/02 05:13:31 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "entities_bonus.h"
#include "sprite_bonus.h"
#include "libft.h"

static void	change_destination(t_entity *entity)
{
	t_list	*save;

	if (entity == NULL || entity->path == NULL)
		return ;
	save = entity->path;
	entity->path = entity->path->next;
	ft_lstdelone(save, free);
}

static void	calculate_move_vector(t_entity *entity, t_vector *result)
{
	t_mlx_coords	*next_pos;
	t_vector		*position;

	next_pos = entity->path->content;
	position = &entity->sprite->position;
	result->x = next_pos->x + 0.5 - position->x;
	result->y = next_pos->y + 0.5 - position->y;
}

void	update_entity_position(t_entity *entity, float delta_time,
	t_list *entities, t_map *map)
{
	t_vector		move;
	float			move_length;

	if (entity->path == NULL
		|| pow(entity->sprite->distance, 2) <= entity->squared_radius)
		return ;
	calculate_move_vector(entity, &move);
	move_length = get_vector_length(&move);
	mutlitply_vector(&move, entity->speed * delta_time / move_length);
	move_entity(entities, &entity->sprite->position, &move, map);
	if (move_length < entity->speed && entity->path->next != NULL)
	{
		if (entity->is_path_circular)
			entity->path = entity->path->next;
		else
			change_destination(entity);
	}
}
