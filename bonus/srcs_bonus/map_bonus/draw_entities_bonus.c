/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_entities_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 19:43:13 by codekiwi          #+#    #+#             */
/*   Updated: 2024/10/02 04:14:47 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "entities_bonus.h"
#include "libft.h"
#include "sprite_bonus.h"

/**
 * @brief Sets the coordinates of the given position onto the map drawing
 * @param position the position to convert into map drawing coords
 * @param coords the structure into which final coords will be saved
 * @param tile_size the size of a tile into the map drawing
 * @param map_draw_coords the coords of the map drawing into the global window
 */
static void	get_coords(
	t_vector *position,
	t_mlx_coords *coords,
	int tile_size,
	t_mlx_coords *map_draw_coords
)
{
	coords->x = (position->x * (float)tile_size) + map_draw_coords->x;
	coords->y = (position->y * (float)tile_size) + map_draw_coords->y;
}

/**
 * @brief Draws the player onto the given image
 * @param draw the t_map_draw element containing drawing params
 * @param player_position the player position
 * @param img the image onto which the player will be drawn
 */
static void	draw_map_player(
	t_map_draw *draw,
	t_vector *player_position,
	t_image *img
)
{
	t_mlx_coords	position;

	get_coords(player_position, &position, draw->tile_size, &draw->coords);
	t_mlx_draw_disk(img, &position, draw->element_radius, MAP_DRAW_COL_PLAYER);
}

/**
 * @brief Draws the rays casted onto the given image
 * @param draw the t_map_draw element containing drawing params
 * @param player_position the player position
 * @param rays the array of casted rays
 * @param img the image onto which rays will be drawn
 */
static void	draw_map_rays(
	t_map_draw *draw,
	t_vector *player_position,
	t_ray *rays,
	t_image *img
)
{
	t_mlx_coords	save;
	t_mlx_coords	pos;
	t_mlx_coords	ray_end;
	size_t			i;

	get_coords(player_position, &save, draw->tile_size, &draw->coords);
	i = -1;
	while (++i < WIN_WIDTH)
	{
		pos.x = save.x;
		pos.y = save.y;
		get_coords(&rays[i].intersection, &ray_end, draw->tile_size, \
			&draw->coords);
		t_mlx_draw_line(img, pos, ray_end, MAP_DRAW_COL_RAYS);
		if (rays[i].slope.x < 0 && rays[i].slope.y > 0)
			ray_end.x += 1;
		else if (rays[i].slope.x > 0 && rays[i].slope.y > 0)
			ray_end.y += 1;
		else if (rays[i].slope.x > 0 && rays[i].slope.y < 0)
			ray_end.x -= 1;
		else
			ray_end.y -= 1;
		t_mlx_draw_line(img, pos, ray_end, MAP_DRAW_COL_RAYS);
	}
}

/**
 * @brief Draws the ennemies onto the given image
 * @param draw the t_map_draw element containing drawing params
 * @param entities the list of ennemies
 * @param img the image onto which ennemies will be drawn
 */
static void	draw_map_ennemies(t_map_draw *draw, t_list *entities, t_image *img)
{
	t_mlx_coords	position;
	t_entity		*entity;

	while (entities != NULL)
	{
		entity = (t_entity *) entities->content;
		get_coords(&entity->sprite->position, &position, draw->tile_size, \
			&draw->coords);
		t_mlx_draw_disk(img, &position, draw->element_radius, \
			MAP_DRAW_COL_ENNEMIES);
		entities = entities->next;
	}
}

/**
 * @brief Draws the entities onto the game image
 * @param draw the t_map_draw element containing drawing params
 * @param game the main game structure containing the entities information
 */
void	draw_map_entities(t_map_draw *draw, t_game *game)
{
	if (draw == NULL || game == NULL)
		return ;
	draw_map_rays(draw, &game->player.position, game->rays, game->mlx.img_buff);
	draw_map_player(draw, &game->player.position, game->mlx.img_buff);
	draw_map_ennemies(draw, game->entities, game->mlx.img_buff);
}
