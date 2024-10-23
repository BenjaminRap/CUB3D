/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 19:11:05 by codekiwi          #+#    #+#             */
/*   Updated: 2024/10/02 06:30:43 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "radar_bonus.h"

/**
 * @brief Rotates coords and saves the result into res_coords
 * @param coords the coordinates to rotate
 * @param res_coords the structure for saving the result
 * @param img_size the size of the image in order to rotate around
 * the img center
 * @param orientation the rotation angle
 */
static void	rotate_coord(
	t_mlx_coords *coords,
	t_mlx_coords *res_coords,
	int img_size,
	float orientation
)
{
	t_mlx_coords	tcoords;

	tcoords.x = coords->x - img_size / 2;
	tcoords.y = coords->y - img_size / 2;
	res_coords->x = (int)((float) tcoords.x * cos(orientation) - \
		(float) tcoords.y * sin(orientation)) + img_size / 2;
	res_coords->y = (int)((float) tcoords.x * sin(orientation) + \
		(float) tcoords.y * cos(orientation)) + img_size / 2;
}

/**
 * @brief Applies a rotation to the curr image in order to make the res image
 * @param curr the image to rotate
 * @param res the image where rotated pixels will be saved
 * @param img_size the size of the radar images
 * @param orientation the rotation angle to apply
 * @note How it works:
 * 	- the function goes through the res image
 * 	- each pixel of the result is evaluated using the pixels from the curr image
 * 	In order to perform this operation, the function evaluates which pixel
 * 	corresponds to the current result pixel onto the curr image
 * 	- transparent pixels are ignored
 */
static void	draw_radar_rotate_process(
	t_image *curr,
	t_image *res,
	int img_size,
	float orientation
)
{
	uint32_t		*curr_addr;
	uint32_t		*res_addr;
	t_mlx_coords	res_coords;
	t_mlx_coords	curr_coords;

	curr_addr = (uint32_t *) curr->addr;
	res_addr = (uint32_t *) res->addr;
	res_coords.x = -1;
	while (++res_coords.x < img_size)
	{
		res_coords.y = -1;
		while (++res_coords.y < img_size)
		{
			if (*(curr_addr + res_coords.x * img_size + res_coords.y) != \
				RAD_COL_TRANSPARENT)
			{
				rotate_coord(&res_coords, &curr_coords, img_size, orientation);
				if (curr_coords.x > 0 && curr_coords.x < img_size \
					&& curr_coords.y > 0 && curr_coords.y < img_size)
					*(res_addr + res_coords.x * img_size + res_coords.y) = \
						*(curr_addr + curr_coords.x * img_size + curr_coords.y);
			}
		}
	}
}

/**
 * @brief Applies a rotation to the radar image
 * @param radar the radar instance to rotate
 * @note How it works:
 * 	- the radar img2's pixels are evaluated as the result of the rotation of
 * 	the radar img's pixels
 * 	- the radar img is replaced with img2
 */
void	draw_radar_rotate(t_radar *radar)
{
	t_image	*curr;
	t_image	*res;

	if (radar == NULL)
		return ;
	curr = radar->img;
	res = radar->img2;
	draw_radar_rotate_process(curr, res, radar->radius * 2, radar->orientation);
	radar->img = res;
	radar->img2 = curr;
}
