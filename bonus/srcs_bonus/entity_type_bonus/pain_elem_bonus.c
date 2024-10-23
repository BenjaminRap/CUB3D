/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pain_elem_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:49:15 by root              #+#    #+#             */
/*   Updated: 2024/10/02 05:15:38 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities_bonus.h"
#include "bullets_bonus.h"
#include "cub3d_bonus.h"
#include "sprite_bonus.h"

static bool	pain_elem_spawn(t_entity *entity, t_sprite *sprite, t_game *game)
{
	t_vector	position;
	t_vector	direction;
	t_entity	*new_lost_soul;

	if (entity->cooldown > 0)
		return (true);
	entity->cooldown = PAIN_ELEM_SPAWN_PAUSE;
	get_entity_direction(&direction, &game->player.position, &sprite->position);
	if (!get_spawn_position(&position, entity, &direction, game))
		return (true);
	new_lost_soul = add_entity(game, 0, 0, ID_MAP_LOST_SOUL);
	if (!new_lost_soul)
		return (false);
	new_lost_soul->sprite->position.x = position.x;
	new_lost_soul->sprite->position.y = position.y;
	set_animation(entity->sprite, &game->anim[IDX_TXTR_PAIN_ELEM_ATTACK]);
	game->anim[IDX_TXTR_PAIN_ELEM_ATTACK].on_end = NULL;
	sprite->next_animation = &game->anim[IDX_TXTR_PAIN_ELEM_WALK];
	return (true);
}

bool	pain_elem_update(t_game *game, t_entity *entity, float delta_time)
{
	float		distance;
	t_sprite	*sprite;

	sprite = entity->sprite;
	distance = get_distance(&sprite->position, &game->player.position);
	sprite->animate = true;
	if (distance < PAIN_ELEM_ATTACK_RANGE)
	{
		stop_walk_animation(entity);
		close_attack(entity, game, PAIN_ELEM_PAUSE);
	}
	else if (!entity->see_player)
		update_entity_position(entity, delta_time, game->entities, game->map);
	else
	{
		stop_walk_animation(entity);
		if (!pain_elem_spawn(entity, sprite, game))
			return (false);
	}
	return (true);
}

void	pain_elem_init(t_entity *entity, t_animation animation[MAP_NB_IDS])
{
	entity->update = pain_elem_update;
	entity->get_killed = entity_get_killed;
	entity->get_damage = entity_get_damage;
	entity->get_chainsawed = entity_get_chainsawed;
	entity->walk = &animation[IDX_TXTR_PAIN_ELEM_WALK];
	entity->pain = &animation[IDX_TXTR_PAIN_ELEM_PAIN];
	entity->death = &animation[IDX_TXTR_PAIN_ELEM_DEATH];
	entity->close_attack = &animation[IDX_TXTR_PAIN_ELEM_ATTACK];
	entity->range_attack = NULL;
	entity->close_damage = PAIN_ELEM_DAMAGE;
	entity->health_point = PAIN_ELEM_HEALTH_POINT;
	entity->speed = PAIN_ELEM_SPEED;
	entity->squared_radius = PAIN_ELEM_SQUARED_RADIUS;
	entity->bullet_sensibility_radius = PAIN_ELEM_SENSIBILITY_RADIUS;
	entity->type = NULL;
	t_sprite_init(entity->sprite, &animation[IDX_TXTR_PAIN_ELEM_WALK],
		WIN_HEIGHT);
	entity->sprite->height = WIN_HEIGHT * PAIN_ELEM_HEIGHT_RATIO;
	entity->reload_probability = PAIN_ELEM_RELOAD_PROBABILITY;
	entity->reload_ratio = PAIN_ELEM_RELOAD_RATIO;
}
