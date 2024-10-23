/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mancubus_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:50:44 by root              #+#    #+#             */
/*   Updated: 2024/07/23 21:17:00 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities_bonus.h"
#include "bullets_bonus.h"
#include "cub3d_bonus.h"
#include "sprite_bonus.h"

bool	mancubus_update(t_game *game, t_entity *entity, float delta_time)
{
	float		distance;
	t_sprite	*sprite;

	sprite = entity->sprite;
	distance = get_distance(&sprite->position, &game->player.position);
	sprite->animate = true;
	if (distance < MANC_CLOSE_ATTACK_RANGE)
	{
		stop_walk_animation(entity);
		close_attack(entity, game, MANC_CLOSE_PAUSE);
	}
	else if (!entity->see_player)
	{
		update_entity_position(entity, delta_time, game->entities, game->map);
		if (entity->path == NULL)
			stop_walk_animation(entity);
	}
	else
	{
		stop_walk_animation(entity);
		range_attack(entity, game, MANC_RANGE_PAUSE);
	}
	return (true);
}

void	mancubus_init(t_entity *entity, t_animation animation[MAP_NB_IDS])
{
	entity->update = mancubus_update;
	entity->get_killed = entity_get_killed;
	entity->get_damage = entity_get_damage;
	entity->get_chainsawed = entity_get_chainsawed;
	entity->walk = &animation[IDX_TXTR_MANC_WALK];
	entity->pain = &animation[IDX_TXTR_MANC_PAIN];
	entity->death = &animation[IDX_TXTR_MANC_DEATH];
	entity->close_attack = &animation[IDX_TXTR_MANC_ATTACK];
	entity->range_attack = &animation[IDX_TXTR_MANC_ATTACK];
	entity->close_damage = MANC_CLOSE_DAMAGE;
	entity->bullet_init = manc_proj_init;
	entity->health_point = MANC_HEALTH_POINT;
	entity->speed = MANC_SPEED;
	entity->squared_radius = MANC_SQUARED_RADIUS;
	entity->bullet_sensibility_radius = MANC_SENSIBILITY_RADIUS;
	entity->type = NULL;
	t_sprite_init(entity->sprite, &animation[IDX_TXTR_MANC_WALK], WIN_HEIGHT);
	entity->sprite->on_ground = true;
	entity->sprite->height = WIN_HEIGHT * MANC_HEIGHT_RATIO;
	entity->reload_probability = MANC_RELOAD_PROBABILITY;
	entity->reload_ratio = MANC_RELOAD_RATIO;
}
