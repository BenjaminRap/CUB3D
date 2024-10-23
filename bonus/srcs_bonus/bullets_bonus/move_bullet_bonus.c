/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bullet_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:58:30 by mhotting          #+#    #+#             */
/*   Updated: 2024/10/02 04:47:33 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bullets_bonus.h"
#include "entities_bonus.h"
#include "sprite_bonus.h"
#include "libft.h"

static t_entity	*bullet_collide_entity(t_list *entities, t_vector *position)
{
	t_list		*current;
	t_entity	*entity;

	if (entities == NULL || position == NULL)
		return (false);
	current = entities;
	while (current)
	{
		entity = current->content;
		if (get_squared_distance(&entity->sprite->position, position) <= \
			entity->bullet_sensibility_radius)
			return (entity);
		current = current->next;
	}
	return (NULL);
}

bool	move_bullet(
	t_list *entities,
	t_bullet *bullet,
	t_vector *move,
	t_map *map
)
{
	t_vector		save;
	t_mlx_coords	tile_pos;
	t_vector		*position;

	if (entities == NULL || bullet == NULL || move == NULL || map == NULL)
		return (false);
	position = &bullet->sprite->position;
	save.x = position->x;
	save.y = position->y;
	add_vector(position, move);
	tile_pos.x = position->x;
	tile_pos.y = position->y;
	bullet->collided_entity = bullet_collide_entity(entities, position);
	if (!is_walkable(map, &tile_pos) || bullet->collided_entity != NULL)
	{
		position->x = save.x;
		position->y = save.y;
		return (false);
	}
	return (true);
}
