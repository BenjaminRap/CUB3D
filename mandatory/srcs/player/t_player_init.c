/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_player_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:23:24 by mhotting          #+#    #+#             */
/*   Updated: 2024/08/27 18:05:26 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

static void	set_player_orientation(t_player *player, t_map *map)
{
	char			*directions;
	float			angle;
	t_mlx_coords	coords;

	coords.x = player->position.x;
	coords.y = player->position.y;
	directions = PLAYER_POS_ORDERED;
	angle = ft_strchr(directions, map->tiles[coords.y][coords.x]) - directions;
	angle *= PI / 2;
	player->orientation = angle;
}

static bool	find_player_position(t_map *map, t_player *player)
{
	t_mlx_coords	coords;
	bool			found_player;

	coords.y = 0;
	found_player = false;
	while ((size_t)coords.y < map->lines_count)
	{
		coords.x = 0;
		while ((size_t)coords.x < map->lines_lengths[coords.y])
		{
			if (ft_strchr(PLAYER_POS_ORDERED, map->tiles[coords.y][coords.x]))
			{
				if (found_player)
					return (error_print(ERR_MULTIPLE_PLAYERS), false);
				found_player = true;
				t_vector_init(&player->position, coords.x, coords.y);
			}
			coords.x++;
		}
		coords.y++;
	}
	if (found_player == false)
		return (error_print(ERR_MISSING_PLAYER), false);
	return (true);
}

bool	t_player_init(t_player *player, t_map *map)
{
	if (player == NULL || map == NULL)
		return (false);
	player->fov_angle = FOV_ANGLE_DEFAULT;
	if (!find_player_position(map, player))
		return (false);
	set_player_orientation(player, map);
	player->position.x += 0.5;
	player->position.y += 0.5;
	player->move_speed[0] = 0.2;
	player->move_speed[1] = 0.1;
	player->move_speed[2] = 0.1;
	player->move_speed[3] = 0.1;
	player->rotation_speed = PI / 90;
	ft_memset(player->walk_direction, 0, 4 * sizeof(bool));
	ft_memset(player->turn_direction, 0, 2 * sizeof(bool));
	return (true);
}
