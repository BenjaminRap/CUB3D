/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 19:41:19 by root              #+#    #+#             */
/*   Updated: 2024/10/02 22:41:35 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "sprite_bonus.h"
#include "utils_bonus.h"
#include "libft.h"
#include "lights_bonus.h"

/**
 * @brief Return the x index of the first column to be drawn
 * @param column The data of the first column
 * @note The sprite can begin out of the screen, this function return the first
 * column index that is in the screen
 */
static float	get_texture_x(t_column *column, t_image *texture)
{
	float	texture_x;

	if (column->coords.x < 0)
	{
		texture_x = -column->coords.x * texture->width;
		texture_x /= column->perceived_height;
		column->coords.x = 0;
		column->texture_x = texture_x;
	}
	else
		texture_x = 0;
	return (texture_x);
}

/**
 * @brief Draw all the columns of the sprite
 * @param column The data of the first column
 * @param sprite The sprite to draw
 * @param img The img in which to draw the sprite
 * @param rays All the rays thrown this frame
 */
static void	draw_all_columns(
	t_column *column,
	t_sprite *sprite,
	t_image *img,
	t_ray	*rays
)
{
	float		texture_x;
	t_image		*texture;
	float		distance;

	texture = sprite->texture->content;
	texture_x = get_texture_x(column, texture);
	while (column->texture_x < texture->width)
	{
		if (column->coords.x >= img->width)
			return ;
		distance = rays[column->coords.x].length;
		if (distance > sprite->distance)
			draw_texture_column(img, column, texture);
		texture_x += sprite->distance * texture->width / sprite->height;
		column->texture_x = texture_x;
		column->coords.x++;
		column->coords.y = column->ranged_start;
	}
}

/**
 * The variable start, end, ranged_start and ranged_end has the same meaning of
 * the one in the draw_walls functions. Except there is no ground_start and
 * ceiling_start
 * @brief Draw a sprite
 */
static void	draw_sprite(t_sprite *sprite, t_game *game)
{
	t_column	column;
	float		scale;

	scale = 1 / sprite->distance;
	column.perceived_height = sprite->height * scale;
	get_sprite_screen_pos(&column, sprite, game, scale);
	column.start = column.coords.y;
	column.end = column.coords.y + column.perceived_height;
	column.ranged_end = range(column.end, 0, WIN_HEIGHT);
	column.ranged_start = range(column.start, 0, WIN_HEIGHT);
	column.texture_start = column.ranged_start - column.start;
	column.texture_x = 0;
	column.coords.y = column.ranged_start;
	column.luminosity = get_luminosity(&sprite->position, game->map, \
		1 / sprite->distance);
	if (is_sprite_aimed(sprite, column.coords.x))
	{
		game->player.aimed_sprite = sprite;
	}
	draw_all_columns(&column, sprite, game->mlx.img_buff, game->rays);
}

void	render_all_sprites(t_game *game)
{
	t_list	*current;

	if (!game->sprites)
		return ;
	game->player.aimed_sprite = NULL;
	get_sprites_distances(game->sprites, &game->player.position);
	sort_list(game->sprites, compare_sprite_distance);
	current = game->sprites;
	while (current != NULL)
	{
		draw_sprite(current->content, game);
		current = current->next;
	}
}
