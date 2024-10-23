/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sky_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:14:16 by brappo            #+#    #+#             */
/*   Updated: 2024/10/02 22:41:27 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "cub3d_bonus.h"
#include "libft.h"

/**
 * @brief return the angel between the x axis and the ray of this column in
 * range [0, 2 * PI].
 * @param The ray of the column.
 */
static float	get_column_angle(t_ray *ray)
{
	float	column_angle;

	column_angle = atan2f(-ray->slope.y, ray->slope.x);
	if (column_angle < 0)
		column_angle += 2 * PI;
	else if (column_angle > 2 * PI)
		column_angle -= 2 * PI;
	return (column_angle);
}

/**
 * When changing the player height, we also rotate his camera to keep a coherent
 * rendering.
 * We must not add the additionnal rotation to the offset calculation : 
 * player->camera_y - player->height does the trick.
 * We then must have a texture_pos whose equal to one thrid of the texture
 * height.
 * @brief Return the texture y start of this column
 */
static size_t	get_texture_start(t_player *player, t_image *sky_texture, \
	float perceived_height)
{
	size_t	texture_start;
	int		offset;
	float	scale_y;

	offset = player->camera_y - player->height;
	offset -= player->orientation.y;
	scale_y = sky_texture->height / perceived_height;
	texture_start = offset + sky_texture->height / 3 / scale_y;
	return (texture_start);
}

/**
 * The sky texture is wrapped around the player, each angle corresponding
 * to a pixel of the sky.
 * The sky move up or down when the player rotate his camera, but doesn't move
 * when the player camera height changes.
 * The sky perceived height is thrice the window height so we can rotate the
 * camera vertically by +WINDOW_HEIGHT or -WINDOW_HEIGHT.
 * @brief Draw a column of the sky
 */
static void	draw_sky_column(size_t column_index, t_ray *ray, t_game *game)
{
	float		column_angle;
	t_column	column;
	t_image		*screen;
	t_image		*texture;

	column_angle = get_column_angle(ray);
	screen = game->mlx.img_buff;
	texture = game->anim[IDX_TXTR_SKY].textures->content;
	column.perceived_height = WIN_HEIGHT * 3;
	column.coords.y = 0;
	column.coords.x = column_index;
	column.texture_x = column_angle * (float)texture->width / (PI * 2);
	column.ranged_end = WIN_HEIGHT;
	column.texture_start = get_texture_start(&game->player, texture, \
		column.perceived_height);
	column.luminosity = 1.0f;
	draw_texture_column(screen, &column, texture);
}

/**
 * @brief Draw the sky
 * @note The sky has to be drawn before everything else
 */
void	draw_sky(t_game *game)
{
	size_t	index;
	t_ray	*ray;

	index = 0;
	while (index < WIN_WIDTH)
	{
		ray = &game->rays[index];
		draw_sky_column(index, ray, game);
		index++;
	}
}

/**
 * @brief return if the position is under a sky
 * @note A sky is either an ID_MAP_SKY or an uppercase letter
 */
bool	is_sky(t_vector *position, t_map *map)
{
	char	character;

	character = map->tiles[(int)position->y][(int)position->x];
	return (character == ID_MAP_SKY || (character >= 'A' && character <= 'Z'));
}
