/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_door_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 15:54:13 by root              #+#    #+#             */
/*   Updated: 2024/10/02 22:40:01 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "door_bonus.h"
#include "entities_bonus.h"
#include "cub3d_bonus.h"

static void	close_door(t_door *door, float delta_time)
{
	door->transition += delta_time * DOOR_SPEED;
	if (door->transition >= 1)
	{
		door->transition = 1;
		door->state = CLOSED;
	}
}

static void	open_door(t_door *door, float delta_time, t_map *map)
{
	door->transition -= delta_time * DOOR_SPEED;
	if (door->transition <= 0)
	{
		door->transition = 0;
		door->state = OPENED;
		door->time_since_opened = 0;
		map->tiles[door->position.y][door->position.x] = ID_MAP_DOOR_OPENED;
	}
}

static bool	can_door_close(t_vector *player_pos, t_mlx_coords *door_pos,
	t_list *entities)
{
	t_vector	door_center_pos;

	if ((int)player_pos->x == door_pos->x && (int)player_pos->y == door_pos->y)
		return (false);
	door_center_pos.x = door_pos->x + 0.5f;
	door_center_pos.y = door_pos->y + 0.5f;
	if (collide_entity(entities, &door_center_pos))
		return (false);
	return (true);
}

static void	update_door(t_door *door, float delta_time, t_game *game)
{
	t_map		*map;
	t_vector	*player_pos;

	map = game->map;
	if (door->state == OPENED)
	{
		player_pos = &game->player.position;
		door->time_since_opened += delta_time;
		if (door->time_since_opened > DOOR_TIME_TO_CLOSE
			&& can_door_close(player_pos, &door->position, game->entities))
		{
			door->state = CLOSING;
			map->tiles[door->position.y][door->position.x] = ID_MAP_DOOR_CLOSED;
		}
	}
	else if (door->state == CLOSING)
		close_door(door, delta_time);
	else if (door->state == OPENING)
		open_door(door, delta_time, map);
}

void	update_doors(t_game *game, float delta_time)
{
	size_t		index;
	t_map		*map;

	index = 0;
	map = game->map;
	while (index < map->door_count)
	{
		update_door(&map->doors[index], delta_time, game);
		index++;
	}
}
