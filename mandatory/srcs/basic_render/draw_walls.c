/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:48:08 by brappo            #+#    #+#             */
/*   Updated: 2024/08/28 17:21:47 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "cub3d.h"

static t_image	*get_texture(t_image textures[4], t_ray *ray)
{
	if (ray->is_vertical)
	{
		if (ray->slope.x > 0)
			return (&textures[3]);
		else
			return (&textures[2]);
	}
	else
	{
		if (ray->slope.y > 0)
			return (&textures[0]);
		else
			return (&textures[1]);
	}
}

static void	draw_wall_column(size_t column_index, t_ray *ray, t_game *game)
{
	t_column	column;
	int			wall_start;
	int			wall_end;
	t_image		*screen;

	screen = game->mlx.img_buff;
	column.coords.y = 0;
	column.coords.x = column_index;
	column.perceived_height = WIN_HEIGHT
		/ (ray->length * cos(ray->angle_from_orientation));
	column.ray = ray;
	wall_start = floorf((WIN_HEIGHT - column.perceived_height) / 2);
	wall_end = floorf((WIN_HEIGHT + column.perceived_height) / 2);
	if (wall_end > WIN_HEIGHT)
		wall_end = WIN_HEIGHT;
	draw_color_column(screen, &column.coords, game->ground_color, wall_start);
	column.texture_start = column.coords.y - wall_start;
	draw_texture_column(game->mlx.img_buff, &column, wall_end,
		get_texture(game->textures, ray));
	draw_color_column(game->mlx.img_buff, &column.coords,
		game->ceiling_color, WIN_HEIGHT);
}

void	draw_walls(t_game *game)
{
	size_t			index;

	index = 0;
	while (index < WIN_WIDTH)
	{
		draw_wall_column(index, &game->rays[index], game);
		index++;
	}
}
