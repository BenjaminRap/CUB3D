/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx_draw_pixel_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:08:26 by mhotting          #+#    #+#             */
/*   Updated: 2024/08/27 14:12:52 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_api_bonus.h"

/**
 * @brief Draws a pixel a the given coordinates of the given color onto img
 * @param img The image onto the pixel will be drawn
 * @param coords The pixel coordinates as a pointer
 * @param color The color of the pixel
*/
void	t_mlx_draw_pixel(
	t_image *img,
	t_mlx_coords *coords,
	uint32_t color
)
{
	*(uint32_t *)(img->addr + \
		(coords->y * img->line_len + (coords->x * img->bpp_factor))) = color;
}

/**
 * @brief Draws a pixel a the given coordinates of the given color onto img
 * @param img The image onto the pixel will be drawn
 * @param coords The pixel coordinates as a pointer
 * @param color The color of the pixel
 * @note Does not write a color over a transparent pixel
*/
void	t_mlx_draw_pixel_alphap(
	t_image *img,
	t_mlx_coords *coords,
	uint32_t color
)
{
	uint32_t	*addr;

	addr = (uint32_t *)(img->addr + (coords->y * img->line_len + (coords->x * \
		img->bpp_factor)));
	if (*addr != 0xFF000000)
		*addr = color;
}
