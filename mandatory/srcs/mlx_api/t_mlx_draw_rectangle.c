/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx_draw_rectangle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:24:55 by mhotting          #+#    #+#             */
/*   Updated: 2024/08/27 14:34:31 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_api.h"

/**
 * @brief Draws a rectangle of the given color, onto the given t_image
 * @param img The image onto we will draw
 * @param coords The starting point coordinates of the line
 * @param size The rectangle's width (size->x) and height (size->y)
 * @param color The color of the rectangle
*/
void	t_mlx_draw_rectangle(
	t_image *img,
	t_mlx_coords *coords,
	t_mlx_coords *size,
	uint32_t color
)
{
	int		i;
	int		j;
	char	*dest_row;

	j = 0;
	while (j < size->y)
	{
		dest_row = img->addr + ((coords->y + j) * img->line_len) \
			+ (coords->x * img->bpp_factor);
		i = 0;
		while (i < size->x)
		{
			*(uint32_t *)(dest_row + (i * img->bpp_factor)) = color;
			i++;
		}
		j++;
	}
}
