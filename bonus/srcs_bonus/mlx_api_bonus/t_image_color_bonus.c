/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_image_color_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 10:24:47 by mhotting          #+#    #+#             */
/*   Updated: 2024/08/27 14:10:54 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_api_bonus.h"

/**
 * @brief Sets all the pixels of the given image to the given color
 * @param img the image whose pixels will be set
 * @param color the color expected
 */
void	t_image_colorize(t_image *img, uint32_t color)
{
	int				x;
	int				y;
	unsigned int	*img_addr;

	if (img == NULL)
		return ;
	img_addr = (unsigned int *) img->addr;
	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			*(img_addr + y * img->width + x) = color;
			x++;
		}
		y++;
	}
}

/**
 * @brief Multiplies all the pixel color components of the image by the given 
 * factor
 * @param img the image to modify
 * @param factor the factor by which each pixel color component will be 
 * multiplied
 */
void	t_image_multiply_each_px(t_image *img, float factor)
{
	int				x;
	int				y;
	unsigned int	*img_addr;

	if (img == NULL || factor < 0.0f)
		return ;
	img_addr = (unsigned int *) img->addr;
	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			multiply_color(img_addr + y * img->width + x, factor);
			x++;
		}
		y++;
	}
}
