/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 18:53:25 by codekiwi          #+#    #+#             */
/*   Updated: 2024/10/02 06:02:45 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "radar_bonus.h"
#include "error_bonus.h"
#include "utils_bonus.h"
#include "config_bonus.h"

/**
 * @brief Initializes the radar images
 * @param radar the radar whose images will be initialized
 * @param mlx_ptr an instance of mlx used for creating images
 * @return true on SUCCESS, false on ERROR
 */
static bool	init_radar_imgs(t_radar *radar, void *mlx_ptr)
{
	radar->img = t_image_init(mlx_ptr, 2 * radar->radius, 2 * radar->radius);
	if (radar->img == NULL)
		return (false);
	radar->img2 = t_image_init(mlx_ptr, 2 * radar->radius, 2 * radar->radius);
	if (radar->img2 == NULL)
	{
		t_image_destroy(mlx_ptr, radar->img, true);
		radar->img = NULL;
		return (false);
	}
	t_image_colorize(radar->img, RAD_COL_TRANSPARENT);
	t_image_colorize(radar->img2, RAD_COL_TRANSPARENT);
	return (true);
}

/**
 * @brief Intializes the given radar
 * @param rad the radar to initialize
 * @param mlx the t_mlx pointer whose information are necessary
 * @return true on SUCCESS, false on ERROR
 */
bool	init_radar(t_radar *rad, t_mlx *mlx)
{
	if (rad == NULL || mlx == NULL)
		return (error_print(ERR_RADAR_CREATION), false);
	rad->orientation = PI / 2.0f;
	rad->radius = (int)((float)mlx->width / RADAR_SIZE_RATIO);
	rad->nb_tiles = RADAR_NB_TILES;
	rad->tile_size = 2 * rad->radius / rad->nb_tiles;
	rad->radius = rad->tile_size * rad->nb_tiles / 2;
	rad->radius_element = rad->tile_size / 2 - 2;
	rad->draw_offset = (2 * rad->radius - rad->nb_tiles * rad->tile_size) / 2;
	rad->coords.x = RADAR_OFFSET;
	rad->coords.y = mlx->height - 2 * rad->radius - RADAR_OFFSET;
	rad->center.x = rad->radius;
	rad->center.y = rad->radius;
	rad->size.x = 2 * rad->radius;
	rad->size.y = 2 * rad->radius;
	rad->needs_update = false;
	if (!init_radar_imgs(rad, mlx->mlx_ptr))
		return (error_print(ERR_RADAR_CREATION), false);
	rad->tiles = create_str_array(rad->nb_tiles, rad->nb_tiles, '0');
	if (rad->tiles == NULL)
	{
		destroy_radar(rad, mlx->mlx_ptr);
		return (error_print(ERR_RADAR_CREATION), false);
	}
	return (true);
}

/**
 * @brief Destroys the given radar instance
 * @param radar the radar to destroy
 * @param mlx_ptr an instance of mlx used for destroying radar's images
 */
void	destroy_radar(t_radar *radar, void *mlx_ptr)
{
	if (radar == NULL)
		return ;
	if (radar->img != NULL)
	{
		t_image_destroy(mlx_ptr, radar->img, true);
		radar->img = NULL;
	}
	if (radar->img2 != NULL)
	{
		t_image_destroy(mlx_ptr, radar->img2, true);
		radar->img2 = NULL;
	}
	if (radar->tiles != NULL)
		ft_free_str_array(&radar->tiles);
}
