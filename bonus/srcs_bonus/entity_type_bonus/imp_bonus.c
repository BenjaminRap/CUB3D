/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imp_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:50:44 by root              #+#    #+#             */
/*   Updated: 2024/07/23 21:15:42 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities_bonus.h"
#include "bullets_bonus.h"
#include "cub3d_bonus.h"
#include "sprite_bonus.h"

bool	imp_update(t_game *game, t_entity *entity, float delta_time)
{
	float		distance;
	t_sprite	*sprite;

	sprite = entity->sprite;
	distance = get_distance(&sprite->position, &game->player.position);
	sprite->animate = true;
	if (distance < IMP_CLOSE_ATTACK_RANGE)
	{
		stop_walk_animation(entity);
		close_attack(entity, game, IMP_CLOSE_PAUSE);
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
		range_attack(entity, game, IMP_RANGE_PAUSE);
	}
	return (true);
}

void	imp_init(t_entity *entity, t_animation animation[MAP_NB_IDS])
{
	entity->update = imp_update;
	entity->get_killed = entity_get_killed;
	entity->get_damage = entity_get_damage;
	entity->get_chainsawed = entity_get_chainsawed;
	entity->walk = &animation[IDX_TXTR_IMP_WALK];
	entity->pain = &animation[IDX_TXTR_IMP_PAIN];
	entity->death = &animation[IDX_TXTR_IMP_DEATH];
	entity->close_attack = &animation[IDX_TXTR_IMP_ATTACK];
	entity->range_attack = &animation[IDX_TXTR_IMP_ATTACK];
	entity->close_damage = IMP_CLOSE_DAMAGE;
	entity->bullet_init = imp_proj_init;
	entity->health_point = IMP_HEALTH_POINT;
	entity->speed = IMP_SPEED;
	entity->squared_radius = IMP_SQUARED_RADIUS;
	entity->bullet_sensibility_radius = IMP_SENSIBILITY_RADIUS;
	entity->type = NULL;
	t_sprite_init(entity->sprite, &animation[IDX_TXTR_IMP_WALK], WIN_HEIGHT);
	entity->sprite->on_ground = true;
	entity->sprite->height = WIN_HEIGHT * IMP_HEIGHT_RATIO;
	entity->reload_probability = IMP_RELOAD_PROBABILITY;
	entity->reload_ratio = IMP_RELOAD_RATIO;
}
