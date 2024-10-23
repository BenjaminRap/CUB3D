/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_screen_position_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:08:17 by root              #+#    #+#             */
/*   Updated: 2024/10/02 04:48:33 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "sprite_bonus.h"
#include "cub3d_bonus.h"
#include "libft.h"

/**
 * @brief Calculate the entity angle of the sprite, relative to the x axis
 * @return The angle in range : [0, 2 * PI]
 */
static float	get_entity_angle(t_vector *sprite_pos, t_vector *player_pos)
{
	float		entity_angle;
	t_vector	entity_direction;

	entity_direction.x = sprite_pos->x - player_pos->x;
	entity_direction.y = sprite_pos->y - player_pos->y;
	entity_angle = atan2f(-entity_direction.y, entity_direction.x);
	if (entity_angle < 0)
		entity_angle += 2 * PI;
	return (entity_angle);
}

/**
 * quadrant 1 : [0, 90]
 * quadrant 4 : [270, 360]
 * If the player is in the quadrant 1 and the entity in the quadrant 4, the 
 * relative angle will be [0, 90] - [270, 360].It will be negative so we need
 * to add 2 * PI;
 * Same thing if the entity is in quadrant 1 and the player in quadrant 4, the
 * relative angle will be [270, 360] - [0, 90], that means a whole turn around
 * the circle so we need to remove 2 * PI;
 * @brief Calculate the angle between the entity and the player
 * @param entity_angle The angle between the entity and the x axis
 * @return The angle between in range [0, 360]
 */
static float	get_relative_angle(float entity_angle, t_player *player)
{
	float	relative_angle;

	relative_angle = player->leftmost_angle - entity_angle;
	if (player->orientation.x > PI / 2 * 3 && entity_angle < PI / 2)
		relative_angle -= 2 * PI;
	else if (player->orientation.x < PI / 2 && entity_angle > PI / 2 * 3)
		relative_angle += 2 * PI;
	return (relative_angle);
}

/**
 * @brief Set the sprite left up corner screen position in the coords variable
 * @param column The column whose coordinates are set.
 * @note Only the perceived height needs to be set in the column variable
 */
void	get_sprite_screen_pos(t_column *column, t_sprite *sprite, \
	t_game *game, float scale)
{
	float		entity_angle;
	float		relative_angle;
	t_player	*player;
	int			offset;

	player = &game->player;
	offset = get_offset(WIN_HEIGHT * scale, player);
	entity_angle = get_entity_angle(&sprite->position, &player->position);
	relative_angle = get_relative_angle(entity_angle, player);
	column->coords.x = relative_angle * player->pixel_by_angle;
	column->coords.x -= column->perceived_height / 2;
	column->coords.y = (WIN_HEIGHT - column->perceived_height) / 2;
	if (sprite->on_ground)
		column->coords.y += (WIN_HEIGHT - sprite->height) / 2 * scale;
	else if (sprite->on_ceiling)
		column->coords.y -= (WIN_HEIGHT - sprite->height) / 2 * scale;
	column->coords.y += offset;
}

/**
 * The sprite is in the middle of the screen if his left is at the left of the
 * middle point and his right at the right of the middle point.
 * We then get the pixel at the middle of the screen, if it's transparent, it
 * returns false
 * @brief Check if the player aimed at the sprite passed as argument
 * @param left_x The x screen position of the left of the sprite
 * @return Return if the sprite passed as argument is at the center of the
 * screen and the current aimed pixel is non transparent
 */
bool	is_sprite_aimed(t_sprite *sprite, int left_x)
{
	int		aimed_column;
	float	height_ratio;
	t_image	*texture;
	char	*color;

	if (sprite == NULL)
		return (false);
	if (left_x > WIN_WIDTH / 2)
		return (false);
	if (left_x + sprite->height / sprite->distance < WIN_WIDTH / 2)
		return (false);
	texture = sprite->texture->content;
	height_ratio = sprite->distance * texture->width / sprite->height;
	aimed_column = (WIN_WIDTH / 2 - left_x) * height_ratio;
	color = t_mlx_get_pixel(texture, aimed_column, texture->height / 2);
	return (*(unsigned int *)color != 0xFF000000);
}
