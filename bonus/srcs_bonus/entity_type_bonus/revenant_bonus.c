/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revenant_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:50:44 by root              #+#    #+#             */
/*   Updated: 2024/07/23 21:15:50 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities_bonus.h"
#include "bullets_bonus.h"
#include "cub3d_bonus.h"
#include "sprite_bonus.h"

bool	revenant_update(t_game *game, t_entity *entity, float delta_time)
{
	float		distance;
	t_sprite	*sprite;

	sprite = entity->sprite;
	distance = get_distance(&sprite->position, &game->player.position);
	sprite->animate = true;
	if (distance < REV_CLOSE_ATTACK_RANGE)
	{
		stop_walk_animation(entity);
		close_attack(entity, game, REV_CLOSE_PAUSE);
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
		range_attack(entity, game, REV_RANGE_PAUSE);
	}
	return (true);
}

void	revenant_init(t_entity *entity, t_animation animation[MAP_NB_IDS])
{
	entity->update = revenant_update;
	entity->get_killed = entity_get_killed;
	entity->get_damage = entity_get_damage;
	entity->get_chainsawed = entity_get_chainsawed;
	entity->walk = &animation[IDX_TXTR_REV_WALK];
	entity->pain = &animation[IDX_TXTR_REV_PAIN];
	entity->death = &animation[IDX_TXTR_REV_DEATH];
	entity->close_attack = &animation[IDX_TXTR_REV_PUNCH];
	entity->range_attack = &animation[IDX_TXTR_REV_SHOOT];
	entity->close_damage = REV_CLOSE_DAMAGE;
	entity->bullet_init = rev_proj_init;
	entity->health_point = REV_HEALTH_POINT;
	entity->speed = REV_SPEED;
	entity->squared_radius = REV_SQUARED_RADIUS;
	entity->bullet_sensibility_radius = REV_SENSIBILITY_RADIUS;
	entity->type = NULL;
	t_sprite_init(entity->sprite, &animation[IDX_TXTR_REV_WALK], WIN_HEIGHT);
	entity->sprite->on_ground = true;
	entity->sprite->height = WIN_HEIGHT * REV_HEIGHT_RATIO;
	entity->reload_probability = REV_RELOAD_PROBABILITY;
	entity->reload_ratio = REV_RELOAD_RATIO;
}
