/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls_part_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:01:44 by mhotting          #+#    #+#             */
/*   Updated: 2024/10/02 22:41:44 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "libft.h"
#include "door_bonus.h"
#include "cub3d_bonus.h"
#include "utils_bonus.h"
#include "lights_bonus.h"

/**
 * @brief Return the texture of the wall, based on the direction or if the wall
 * is a door
 * @param anim All the game animations / textures
 * @return A pointer on the texture
 */
static t_image	*get_texture(t_animation anim[MAP_NB_IDS], t_ray *ray)
{
	if (ray->is_door)
		return (anim[IDX_TXTR_DOOR].textures->content);
	if (ray->is_vertical)
	{
		if (ray->slope.x > 0)
			return (anim[IDX_TXTR_E].textures->content);
		else
			return (anim[IDX_TXTR_W].textures->content);
	}
	else
	{
		if (ray->slope.y > 0)
			return (anim[IDX_TXTR_N].textures->content);
		else
			return (anim[IDX_TXTR_S].textures->content);
	}
}

/**
 * @return The x index of the pixel on that texture
 */
static int	pixel_column_on_texture(t_ray *ray, int texture_width)
{
	int		column;
	float	texture_relative_position;
	double	temp;

	if (ray->is_vertical)
		texture_relative_position = modf(ray->intersection.y, &temp);
	else
		texture_relative_position = modf(ray->intersection.x, &temp);
	if (ray->is_door)
		texture_relative_position = ray->door->transition \
			- texture_relative_position;
	column = floorf(texture_relative_position * texture_width);
	return (column);
}

/**
 * ceiling start / ground start :
 * Represent the ceiling start / wall start or ground start / wall end, except
 * they are not affected by the offsets.
 * They are used to calculate the pixel position of the wall or ground.
 * start / end : 
 * It's the position of the start/end but affected by the offsets.
 * ranged_start / ranged_end :
 * Those are the real position the drawing start or end by, they'r between
 * [0,WIN_HEIGHT].
 * @brief Draw a column of the screen
 * @param column_index The index of the column to draw [0,WIn_HEIGHT]
 */
static void	draw_wall_column(size_t column_index, t_ray *ray, t_game *game)
{
	t_column	column;
	t_image		*texture;
	int			offset;
	t_vector	position;

	position.x = game->player.position.x + ray->slope.x * ray->length;
	position.y = game->player.position.y - ray->slope.y * ray->length;
	column.coords.x = column_index;
	column.perceived_height = WIN_HEIGHT / (ray->length * ray->cos_angle);
	offset = get_offset(column.perceived_height, &game->player);
	column.ceiling_start = (WIN_HEIGHT - column.perceived_height) / 2;
	column.start = column.ceiling_start + offset;
	column.ceiling_start = WIN_HEIGHT - column.ceiling_start;
	column.ground_start = (WIN_HEIGHT + column.perceived_height) / 2;
	column.end = column.ground_start + offset;
	column.ranged_end = range(column.end, 0, WIN_HEIGHT);
	column.ranged_start = range(column.start, 0, WIN_HEIGHT);
	column.coords.y = column.ranged_start;
	column.texture_start = column.coords.y - column.start;
	texture = get_texture(game->anim, ray);
	column.texture_x = pixel_column_on_texture(ray, texture->width);
	draw_ceiling(&column, column.coords.y - 1, game, ray);
	column.luminosity = get_luminosity(&position, game->map, 1 / ray->length);
	draw_texture_column(game->mlx.img_buff, &column, texture);
	draw_ground(&column, column.coords.y, game, ray);
}

void	draw_walls_part(t_game *game, size_t start, size_t end)
{
	size_t	i;

	i = start;
	while (i < end)
	{
		draw_wall_column(i, &game->rays[i], game);
		i++;
	}
}
