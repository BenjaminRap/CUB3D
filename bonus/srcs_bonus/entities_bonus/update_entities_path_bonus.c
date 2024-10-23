/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_entities_path_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 15:05:48 by brappo            #+#    #+#             */
/*   Updated: 2024/10/02 04:18:19 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities_bonus.h"
#include "cub3d_bonus.h"
#include "pathfinding_bonus.h"
#include "libft.h"
#include "sprite_bonus.h"

static bool	can_see(t_vector *position, t_vector *point, t_game *game)
{
	t_ray		ray;
	float		distance;
	float		ray_length;

	ray.slope.x = point->x - position->x;
	ray.slope.y = position->y - point->y;
	distance = get_vector_length(&ray.slope);
	if (distance >= MAX_DISTANCE)
		return (false);
	ray.slope.x /= distance;
	ray.slope.y /= distance;
	ray_length = raycast(*position, game, &ray, MAX_DISTANCE);
	return (ray_length >= distance);
}

static void	update_path(t_entity *entity, t_game *game)
{
	t_mlx_coords	start;
	t_mlx_coords	end;

	ft_lstclear(&entity->path, free);
	start.x = entity->sprite->position.x;
	start.y = entity->sprite->position.y;
	end.x = game->player.position.x;
	end.y = game->player.position.y;
	entity->path = find_path(&start, &end, game->map);
}

void	update_entities_path(t_game *game)
{
	t_list		*current;
	t_entity	*entity;
	size_t		entity_updated;

	if (game == NULL || game->entities == NULL)
		return ;
	current = game->last_entity_updated;
	if (current == NULL)
		current = game->entities;
	entity_updated = 0;
	while (entity_updated < ENTITY_UPDATE_PER_FRAME)
	{
		current = current->next;
		if (current == NULL)
			current = game->entities;
		entity = current->content;
		entity->see_player = can_see(&entity->sprite->position, \
			&game->player.position, game);
		if (entity->see_player)
			update_path(entity, game);
		entity_updated++;
	}
	game->last_entity_updated = current;
}
