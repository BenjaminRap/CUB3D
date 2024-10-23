/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_shoot_bullet_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 11:39:12 by brappo            #+#    #+#             */
/*   Updated: 2024/10/02 04:19:34 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "entities_bonus.h"
#include "bullets_bonus.h"
#include "cub3d_bonus.h"
#include "sprite_bonus.h"
#include "libft.h"

bool	get_spawn_position(t_vector *result, t_entity *entity,
	t_vector *direction, t_game *game)
{
	float			radius;
	t_mlx_coords	tile_pos;

	radius = sqrt(entity->squared_radius) + 0.1f;
	result->x = entity->sprite->position.x + direction->x * radius;
	result->y = entity->sprite->position.y + direction->y * radius;
	tile_pos.x = result->x;
	tile_pos.y = result->y;
	return (is_walkable(game->map, &tile_pos)
		&& !collide_entity(game->entities, result));
}

void	get_entity_direction(t_vector *result, t_vector *player_pos,
	t_vector *entity_pos)
{
	result->x = player_pos->x - entity_pos->x;
	result->y = player_pos->y - entity_pos->y;
	normalize_vector(result);
}

bool	entity_shoot_bullet(t_game *game, t_sprite *entity_sprite)
{
	t_vector	direction;
	t_vector	position;
	t_list		*entity_node;
	t_entity	*entity;

	entity_node = ft_lstfind(game->entities, entity_sprite,
			is_sprite_of_entity);
	if (entity_node == NULL)
		return (false);
	entity = entity_node->content;
	get_entity_direction(&direction, &game->player.position,
		&entity->sprite->position);
	if (!get_spawn_position(&position, entity, &direction, game))
		return (true);
	return (shoot_bullet_from_entity(game, &position, &direction, \
		entity->bullet_init));
}
