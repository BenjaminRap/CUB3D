/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceiling_ground_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:24:21 by brappo            #+#    #+#             */
/*   Updated: 2024/10/02 22:41:18 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "cub3d_bonus.h"
#include "libft.h"
#include "utils_bonus.h"
#include "lights_bonus.h"

/**
 * @brief Return the world position of a pixel
 * @param ray The ray of the pixel column
 * @param result The vector in which the pixel position will be written
 * @param inv_dist the inverse distance from the pixel to the player
 */
static	void	get_pixel_world_pos(t_ray *ray,
	t_vector *player_position, t_vector *result, float inv_dist)
{
	result->x = player_position->x + ray->slope.x / inv_dist;
	result->y = player_position->y - ray->slope.y / inv_dist;
}

/**
 * @brief Draw a ground or ceiling pixel
 * @param position The world position of the pixel
 * @param addr The address the pixel will be drawn into
 * @param texture the texture of the ground/ceiling
 * @param inv_dist the inverse distanc eof the pixel from the player
 * @note We remove the integer part of position because we need the decimal part
 * to calculate the texture coordinate. So position wiil be changed in this
 * function.
 */
static void	draw_pixel_from_texture(t_vector *position, char *addr,
	t_image *texture, float luminosity)
{
	t_mlx_coords	color_coords;
	unsigned int	color;

	position->x -= (int)position->x;
	position->y -= (int)position->y;
	color_coords.x = position->x * texture->width;
	color_coords.y = position->y * texture->height;
	color = *(unsigned int *)(texture->addr + \
		color_coords.y * texture->line_len \
		+ (color_coords.x * texture->bpp_factor));
	multiply_color(&color, luminosity);
	*(unsigned int *)addr = color;
}

/**
 * @brief Return the initial inverse distance of a pixel, it does only work for
 * the first ground / ceiling pixel of the column
 * @param start the y pixel position of the wall / ground start
 * @param cos_angle the cosinus of the angle of this row from the player
 * orientation
 * @return The inverse distance
 */
static float	get_inv_dist(int start, float cos_angle)
{
	float	inv_dist;

	inv_dist = start * cos_angle / (WIN_HEIGHT / 2) - cos_angle;
	return (inv_dist);
}

/**
 * To draw the ground we need the world position of the pixel, for that, we
 * need to know his distance from the player.
 * I calculate the inverse distance because it allows me to just add a variable
 * each loop instead of recalculating the whole thing.
 * inv_dist = inverse distance
 * inv_dist_unit = inverse_distance_unit
 * When the ground start is out of the screen, we need to increase the initial
 * distance, due to those out of the screen pixels.We just multiply the unit by
 * the amount of pixels that are out of the screen : (-column->end).
 * @brief Draw the ground texture from start to WIN_HEIGHT
 * @param column The column data to draw
 * @param start The pixel y start
*/
void	draw_ground(t_column *column, int start, t_game *game, t_ray *ray)
{
	float		inv_dist;
	float		inv_dist_unit;
	t_vector	pixel_pos;
	char		*addr;
	int			height_diff;

	height_diff = game->player.camera_y_diff;
	inv_dist = get_inv_dist(column->ground_start, ray->cos_angle);
	inv_dist_unit = ray->cos_angle / (WIN_HEIGHT / 2 - height_diff);
	inv_dist += max_int(-column->end, 0) * inv_dist_unit;
	addr = t_mlx_get_pixel(game->mlx.img_buff, column->coords.x, start);
	while (start < WIN_HEIGHT)
	{
		get_pixel_world_pos(ray, &game->player.position, &pixel_pos, inv_dist);
		column->luminosity = get_luminosity(&pixel_pos, game->map, inv_dist);
		draw_pixel_from_texture(&pixel_pos, addr,
			game->anim[IDX_TXTR_FLOOR].textures->content, column->luminosity);
		start++;
		inv_dist += inv_dist_unit;
		addr += game->mlx.img_buff->line_len;
	}
}

/**
 * Look at the commentary of draw_ground
 * @brief Draw the ground texture from 0 to start
 * @param column The column data to draw
 * @param start The pixel y start
 */
void	draw_ceiling(t_column *column, int start, t_game *game, t_ray *ray)
{
	float		inv_dist;
	float		inv_dist_unit;
	t_vector	pixel_pos;
	char		*addr;
	int			height_diff;

	height_diff = game->player.camera_y_diff;
	inv_dist = get_inv_dist(column->ceiling_start, ray->cos_angle);
	inv_dist_unit = ray->cos_angle / (WIN_HEIGHT / 2 + height_diff);
	inv_dist += max_int(column->start - WIN_HEIGHT, 0) * inv_dist_unit;
	addr = t_mlx_get_pixel(game->mlx.img_buff, column->coords.x, start);
	while (start >= 0)
	{
		get_pixel_world_pos(ray, &game->player.position, &pixel_pos, inv_dist);
		if (!is_sky(&pixel_pos, game->map))
		{
			draw_pixel_from_texture(&pixel_pos, addr, \
				game->anim[IDX_TXTR_CEIL].textures->content, \
				get_luminosity(&pixel_pos, game->map, inv_dist));
		}
		start--;
		inv_dist += inv_dist_unit;
		addr -= game->mlx.img_buff->line_len;
	}
}
