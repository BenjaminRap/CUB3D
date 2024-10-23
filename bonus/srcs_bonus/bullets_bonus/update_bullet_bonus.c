/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_bullet_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:17:13 by brappo            #+#    #+#             */
/*   Updated: 2024/10/02 03:54:15 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bullets_bonus.h"
#include "libft.h"
#include "sprite_bonus.h"
#include "cub3d_bonus.h"

static void	update_bullet(t_game *game, t_bullet *bullet, float delta_time)
{
	t_vector	realtime_move;

	if (game == NULL || bullet == NULL || bullet->sprite == NULL)
		return ;
	realtime_move.x = bullet->move.x * delta_time * bullet->speed;
	realtime_move.y = bullet->move.y * delta_time * bullet->speed;
	if (
		bullet->use != NULL
		&& (
			!move_bullet(game->entities, bullet, &realtime_move, game->map)
			|| (
				!bullet->player_protected
				&& bullet->sprite->distance < PLAYER_RADIUS
			)
		)
	)
		bullet->use(game, bullet);
}

void	update_bullets(t_game *game, float delta_time)
{
	t_list		*current;
	t_bullet	*bullet;

	if (game == NULL || game->bullets == NULL)
		return ;
	current = game->bullets;
	while (current)
	{
		bullet = current->content;
		current = current->next;
		update_bullet(game, bullet, delta_time);
	}
}
