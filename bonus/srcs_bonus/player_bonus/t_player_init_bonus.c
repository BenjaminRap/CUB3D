/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_player_init_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:23:24 by mhotting          #+#    #+#             */
/*   Updated: 2024/10/02 03:44:28 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "libft.h"
#include "error_bonus.h"

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
	if (angle > 2 * PI)
		angle -= 2 * PI;
	player->orientation.x = angle;
	player->orientation.y = 0;
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

bool	t_player_init(t_player *player, t_map *map, t_game *game)
{
	if (player == NULL || map == NULL || !find_player_position(map, player))
		return (error_print(ERR_PLAYER_CREATION), false);
	player->fov_angle = FOV_ANGLE_DEFAULT;
	set_player_orientation(player, map);
	player->position.x += 0.5;
	player->position.y += 0.5;
	player->pixel_by_angle = WIN_WIDTH / player->fov_angle;
	player->move_speed[0] = PLAYER_SPEED_FORWARD;
	player->move_speed[1] = PLAYER_SPEED_LEFT;
	player->move_speed[2] = PLAYER_SPEED_BACKWARD;
	player->move_speed[3] = PLAYER_SPEED_RIGHT;
	t_vector_init(&player->rotation_speed, 0.0f, 0.0f);
	player->health_point = PLAYER_HEALTH_POINT;
	player->look_ray = &game->rays[(int)WIN_WIDTH / 2];
	player->vertical_move = 0;
	player->height = PLAYER_HEIGHT_RATIO * WIN_HEIGHT;
	player->camera_y = player->height;
	player->camera_y_diff = get_camera_height_diff(player->camera_y);
	player->jump_force = PLAYER_JUMP_FORCE_RATIO * WIN_HEIGHT;
	player->gravity_force = GRAVITY_FORCE_RATIO * WIN_HEIGHT;
	player->is_grounded = true;
	return (true);
}
