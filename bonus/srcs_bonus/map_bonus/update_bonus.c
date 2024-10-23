/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:31:34 by mhotting          #+#    #+#             */
/*   Updated: 2024/07/19 12:38:01 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities_bonus.h"
#include "door_bonus.h"
#include "cub3d_bonus.h"
#include "libft.h"
#include "sprite_bonus.h"

/**
 * @brief Removes all the moving characters from the map
 * @param map the map to clean
 * @note All the removed elements are replaced with an empty tile character
 */
static void	clear_map(t_map *map)
{
	size_t	i;
	size_t	j;
	char	*character;

	i = 0;
	while (i < map->lines_count)
	{
		j = 0;
		while (j < map->lines_lengths[i])
		{
			character = &map->tiles[i][j];
			if (ft_strchr(MAP_MOVING_CHARS, *character) != NULL)
			{
				if (*character >= 'A' && map->tiles[i][j] <= 'Z')
					*character = ID_MAP_SKY;
				else
					*character = ID_MAP_TILE;
			}
			j++;
		}
		i++;
	}
}

/**
 * @brief Adds the player onto the map
 * @param map the map
 * @param player the player instance
 */
static void	add_player_to_map(t_map *map, t_player *player)
{
	t_vector		*player_pos;
	char			*character;

	player_pos = &player->position;
	if (!is_in_bounds(player_pos, map))
		return ;
	character = &map->tiles[(int)player_pos->y][(int)player_pos->x];
	if (is_sky(player_pos, map))
		*character = ID_MAP_PLAYER - 32;
	else
		*character = ID_MAP_PLAYER;
}

/**
 * @brief Adds the entities onto the map
 * @param map the map
 * @param entities an list of all the game entities
 */
static void	add_entities_to_map(t_map *map, t_list *entities)
{
	t_entity		*entity;
	t_vector		*entity_pos;
	char			*character;

	while (entities != NULL)
	{
		entity = (t_entity *) entities->content;
		entities = entities->next;
		if (entity == NULL || entity->sprite == NULL)
			continue ;
		entity_pos = &entity->sprite->position;
		character = &map->tiles[(int)entity_pos->y][(int)entity_pos->x];
		if (is_sky(entity_pos, map))
			*character = ID_MAP_ENTITY - 32;
		else
			*character = ID_MAP_ENTITY;
	}
}

/**
 * @brief Adds the doors onto the map
 * @param map the map
 * @param doors an array of all the game doors
 * @param door_count the number of doors into doors
 */
static void	add_doors_to_map(t_map *map, t_door *doors, size_t door_count)
{
	size_t			i;
	t_mlx_coords	*door_coords;

	if (doors == NULL)
		return ;
	i = 0;
	while (i < door_count)
	{
		door_coords = &doors[i].position;
		if (doors[i].state == OPENED)
			map->tiles[door_coords->y][door_coords->x] = ID_MAP_DOOR_OPENED;
		else
			map->tiles[door_coords->y][door_coords->x] = ID_MAP_DOOR_CLOSED;
		i++;
	}
}

/**
 * @brief Updates the map instance with all game elements
 * @param map the map to update
 * @param game the main game structure
 */
void	update_map(t_map *map, t_game *game)
{
	if (map == NULL || game == NULL)
		return ;
	clear_map(map);
	add_doors_to_map(map, map->doors, map->door_count);
	add_player_to_map(map, &game->player);
	add_entities_to_map(map, game->entities);
}
