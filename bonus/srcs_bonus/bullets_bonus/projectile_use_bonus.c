/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projectile_use_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:06:05 by mhotting          #+#    #+#             */
/*   Updated: 2024/10/02 04:21:14 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities_bonus.h"
#include "bullets_bonus.h"
#include "cub3d_bonus.h"
#include "libft.h"
#include "sprite_bonus.h"

void	entity_projectile_use(t_game *game, t_bullet *bullet)
{
	t_sprite	*sprite;
	t_vector	*player_pos;

	if (game == NULL || bullet == NULL)
		return ;
	sprite = bullet->sprite;
	if (bullet->animation != NULL)
		set_animation(sprite, bullet->animation);
	sprite->next_animation = NULL;
	player_pos = &game->player.position;
	if (get_distance(player_pos, &bullet->sprite->position) < PLAYER_RADIUS)
		player_get_damage(game, bullet->damage);
	ft_lst_remove_if(&game->bullets, bullet, equal, free);
}

void	player_basic_projectile_use(t_game *game, t_bullet *bullet)
{
	t_sprite	*sprite;

	if (game == NULL || bullet == NULL)
		return ;
	sprite = bullet->sprite;
	if (bullet->animation != NULL)
		set_animation(sprite, bullet->animation);
	sprite->next_animation = NULL;
	if (bullet->collided_entity != NULL)
	{
		if (bullet->damage > 0)
			entity_get_damage(game, bullet->collided_entity, bullet->damage);
		if (bullet->cooldown_time > 0.0f)
			bullet->collided_entity->cooldown_from_player = \
				bullet->cooldown_time;
	}
	ft_lst_remove_if(&game->bullets, bullet, equal, free);
}
