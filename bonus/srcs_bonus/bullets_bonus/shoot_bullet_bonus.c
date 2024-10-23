/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot_bullet_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:06:25 by brappo            #+#    #+#             */
/*   Updated: 2024/10/02 04:49:39 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprite_bonus.h"
#include "bullets_bonus.h"
#include "config_bonus.h"
#include "cub3d_bonus.h"
#include "libft.h"

static t_bullet	*bullet_create(
	t_game *game,
	t_vector *position,
	t_vector *direction
)
{
	t_bullet	*bullet;
	t_sprite	*sprite;

	if (game == NULL || position == NULL || direction == NULL)
		return (false);
	bullet = ft_calloc(1, sizeof(t_bullet));
	if (bullet == NULL)
		return (NULL);
	sprite = add_sprite(game, position->x, position->y, 'c');
	if (sprite == NULL)
	{
		free(bullet);
		return (NULL);
	}
	bullet->sprite = sprite;
	bullet->move = *direction;
	bullet->player_protected = false;
	bullet->collided_entity = NULL;
	return (bullet);
}

static bool	bullet_config_and_save(t_game *game, t_bullet *bullet)
{
	t_list		*new_node;

	new_node = ft_lstnew(bullet);
	if (new_node == NULL)
		return (false);
	ft_lstadd_front(&game->bullets, new_node);
	bullet->sprite->distance = \
		get_distance(&bullet->sprite->position, &game->player.position);
	bullet->sprite->height = BULLET_HEIGHT_WINDOW_RATIO * WIN_HEIGHT;
	return (true);
}

bool	shoot_bullet_from_entity(
	t_game *game,
	t_vector *position,
	t_vector *direction,
	void (*init_bullet)(t_animation anim[MAP_NB_IDS], t_bullet *)
)
{
	t_bullet	*bullet;

	if (
		game == NULL || position == NULL \
		|| direction == NULL || init_bullet == NULL
	)
		return (false);
	bullet = bullet_create(game, position, direction);
	if (bullet == NULL)
		return (false);
	init_bullet(game->anim, bullet);
	if (!bullet_config_and_save(game, bullet))
		return (free(bullet), false);
	return (true);
}

bool	shoot_bullet_from_player(
	t_game *game,
	t_vector *position,
	t_vector *direction,
	void (*init_bullet)(t_bullet *, t_weapon *)
)
{
	t_bullet	*bullet;

	if (
		game == NULL || position == NULL \
		|| direction == NULL || init_bullet == NULL
	)
		return (false);
	bullet = bullet_create(game, position, direction);
	if (bullet == NULL)
		return (false);
	init_bullet(bullet, game->player.weapon_info.curr_weapon);
	if (!bullet_config_and_save(game, bullet))
		return (free(bullet), false);
	return (true);
}
