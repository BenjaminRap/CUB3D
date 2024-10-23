/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_image_resize_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:28:56 by mhotting          #+#    #+#             */
/*   Updated: 2024/08/27 14:11:29 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_api_bonus.h"
#include "mlx.h"
#include "vector_bonus.h"

static void	t_image_resize_replace_old(
	t_image *new,
	t_image *img,
	void *mlx_ptr
)
{
	mlx_destroy_image(mlx_ptr, img->ptr);
	img->addr = new->addr;
	img->bpp = new->bpp;
	img->bpp_factor = new->bpp_factor;
	img->width = new->width;
	img->height = new->height;
	img->ptr = new->ptr;
	img->endian = new->endian;
	img->line_len = new->line_len;
	free(new);
}

bool	t_image_resize(void *mlx_ptr, t_image *img, t_mlx_coords *size)
{
	t_image			*new;
	t_mlx_coords	coord;
	t_mlx_coords	src_coord;
	t_vector		factors;

	if (img->width == size->x && img->height == size->y)
		return (true);
	new = t_image_init(mlx_ptr, size->x, size->y);
	if (new == NULL)
		return (false);
	factors.x = ((float) img->width) / ((float) size->x);
	factors.y = ((float) img->height) / ((float) size->y);
	coord.y = -1;
	while (++coord.y < size->y)
	{
		src_coord.y = (int)((float) coord.y * factors.y);
		coord.x = -1;
		while (++coord.x < size->x)
		{
			src_coord.x = (int)((float) coord.x * factors.x);
			*(((int *) new->addr) + coord.y * size->x + coord.x) = \
				*(((int *) img->addr) + src_coord.y * img->width + src_coord.x);
		}
	}
	return (t_image_resize_replace_old(new, img, mlx_ptr), true);
}
