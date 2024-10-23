/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entities_actions_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 19:30:35 by root              #+#    #+#             */
/*   Updated: 2024/10/02 04:23:27 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "entities_bonus.h"
#include "libft.h"
#include "sprite_bonus.h"

void	entity_get_killed(t_game *game, t_entity *entity)
{
	if (game == NULL || entity == NULL || game->entities == NULL)
		return ;
	if (game->last_entity_updated->content == entity)
		game->last_entity_updated = game->last_entity_updated->next;
	entity->sprite->locked = false;
	set_animation(entity->sprite, entity->death);
	entity->sprite->next_animation = NULL;
	ft_lst_remove_if(&game->entities, entity, equal, t_entity_destroy);
	return ;
}

void	entity_get_damage(t_game *game, t_entity *entity, size_t damage)
{
	if (game == NULL || entity == NULL || game->entities == NULL)
		return ;
	set_animation(entity->sprite, entity->pain);
	entity->sprite->next_animation = entity->walk;
	damage_entity(game, entity, damage);
	return ;
}

void	entity_get_chainsawed(t_game *game, t_entity *entity, size_t damage)
{
	if (game == NULL || entity == NULL || game->entities == NULL)
		return ;
	set_animation(entity->sprite, entity->pain);
	entity->sprite->next_animation = entity->walk;
	if (entity->health_point <= damage)
	{
		reload_weapons_randomly(game->weapons, entity->reload_ratio, \
			entity->reload_probability);
		entity->get_killed(game, entity);
	}
	else
		entity->health_point -= damage;
}

void	stop_walk_animation(t_entity *entity)
{
	if (entity->sprite->animation == entity->walk)
		entity->sprite->animate = false;
}
