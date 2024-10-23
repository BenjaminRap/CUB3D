/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:39:40 by mhotting          #+#    #+#             */
/*   Updated: 2024/10/02 05:51:29 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "entities_bonus.h"
#include "player_bonus.h"

static float	calc_gap(float move_value)
{
	float	gap;

	if (fabs(move_value) < 0.00001f)
		gap = 0.0f;
	else if (move_value < 0.0f)
		gap = -1.0f;
	else
		gap = 1.0f;
	gap *= PLAYER_MIN_DIST_TO_WALL;
	return (gap);
}

void	move_player(
	t_list *entities,
	t_vector *position,
	t_vector *move,
	t_map *map
)
{
	t_vector		new;
	t_vector		save;
	t_mlx_coords	tile_pos;
	float			gap;

	new.x = position->x;
	new.y = position->y;
	save.x = position->x;
	save.y = position->y;
	add_vector(&new, move);
	gap = calc_gap(move->x);
	tile_pos.x = new.x + gap;
	tile_pos.y = position->y;
	if (is_walkable(map, &tile_pos))
		position->x = new.x;
	gap = calc_gap(move->y);
	tile_pos.x = position->x;
	tile_pos.y = new.y + gap;
	if (is_walkable(map, &tile_pos))
		position->y = new.y;
	if (collide_entity(entities, position))
	{
		position->x = save.x;
		position->y = save.y;
	}
}
