/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boh_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:49:15 by root              #+#    #+#             */
/*   Updated: 2024/07/19 17:14:28 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities_bonus.h"
#include "bullets_bonus.h"
#include "cub3d_bonus.h"
#include "sprite_bonus.h"

bool	boh_update(t_game *game, t_entity *entity, float delta_time)
{
	t_player	*player;
	float		distance;
	t_sprite	*sprite;

	sprite = entity->sprite;
	player = &game->player;
	distance = get_distance(&sprite->position, &player->position);
	sprite->animate = true;
	if (distance < BOH_CLOSE_ATTACK_RANGE)
	{
		stop_walk_animation(entity);
		close_attack(entity, game, BOH_CLOSE_PAUSE);
	}
	else
	{
		if (entity->see_player)
			range_attack(entity, game, BOH_RANGE_PAUSE);
		update_entity_position(entity, delta_time, game->entities, game->map);
		if (entity->path == NULL)
			stop_walk_animation(entity);
	}
	return (true);
}

void	boh_init(t_entity *entity, t_animation animation[MAP_NB_IDS])
{
	entity->update = boh_update;
	entity->get_killed = entity_get_killed;
	entity->get_damage = entity_get_damage;
	entity->get_chainsawed = entity_get_chainsawed;
	entity->walk = &animation[IDX_TXTR_BOH_WALK];
	entity->pain = &animation[IDX_TXTR_BOH_PAIN];
	entity->death = &animation[IDX_TXTR_BOH_DEATH];
	entity->close_attack = &animation[IDX_TXTR_BOH_ATTACK];
	entity->range_attack = &animation[IDX_TXTR_BOH_ATTACK];
	entity->close_damage = BOH_CLOSE_DAMAGE;
	entity->bullet_init = boh_proj_init;
	entity->health_point = BOH_HEALTH_POINT;
	entity->speed = BOH_SPEED;
	entity->squared_radius = BOH_SQUARED_RADIUS;
	entity->bullet_sensibility_radius = BOH_SENSIBILITY_RADIUS;
	entity->type = NULL;
	t_sprite_init(entity->sprite, &animation[IDX_TXTR_BOH_WALK], WIN_HEIGHT);
	entity->sprite->on_ground = true;
	entity->sprite->height = WIN_HEIGHT * BOH_HEIGHT_RATIO;
	entity->reload_probability = BOH_RELOAD_PROBABILITY;
	entity->reload_ratio = BOH_RELOAD_RATIO;
}
