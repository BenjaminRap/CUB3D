/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_doors_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:24:20 by brappo            #+#    #+#             */
/*   Updated: 2024/10/02 22:39:24 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "door_bonus.h"
#include "cub3d_bonus.h"

t_door	*find_door_at_position(t_mlx_coords *position, t_game *game)
{
	size_t	index;
	t_door	*last_door_seen;
	t_map	*map;

	index = 0;
	last_door_seen = game->player.last_door_seen;
	if (last_door_seen != NULL
		&& last_door_seen->position.x == position->x
		&& last_door_seen->position.y == position->y)
		return (last_door_seen);
	map = game->map;
	while (index < map->door_count)
	{
		if (position->x == map->doors[index].position.x
			&& position->y == map->doors[index].position.y)
		{
			last_door_seen = map->doors + index;
			return (map->doors + index);
		}
		index++;
	}
	return (NULL);
}
