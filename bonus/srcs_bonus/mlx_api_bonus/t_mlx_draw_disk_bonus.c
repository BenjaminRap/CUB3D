/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx_draw_disk_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 22:53:10 by codekiwi          #+#    #+#             */
/*   Updated: 2024/07/19 13:47:32 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_api_bonus.h"

void	t_mlx_draw_disk(
	t_image *img,
	t_mlx_coords *coords,
	int radius,
	uint32_t color
)
{
	int				err;
	t_mlx_coords	xy;
	t_mlx_coords	temp;

	t_mlx_circle_disk_init_vars(&xy, &err, radius);
	while (xy.x >= xy.y)
	{
		temp.x = coords->x - xy.x - 1;
		while (++temp.x <= coords->x + xy.x)
		{
			temp.y = coords->y + xy.y;
			t_mlx_draw_pixel(img, &temp, color);
			temp.y = coords->y - xy.y;
			t_mlx_draw_pixel(img, &temp, color);
		}
		temp.x = coords->x - xy.y - 1;
		while (++temp.x <= coords->x + xy.y)
		{
			temp.y = coords->y + xy.x;
			t_mlx_draw_pixel(img, &temp, color);
			temp.y = coords->y - xy.x;
			t_mlx_draw_pixel(img, &temp, color);
		}
		t_mlx_circle_disk_update_err(&xy, &err);
	}
}

void	t_mlx_draw_disk_alphap(
	t_image *img,
	t_mlx_coords *coords,
	int radius,
	uint32_t color
)
{
	int				err;
	t_mlx_coords	xy;
	t_mlx_coords	temp;

	t_mlx_circle_disk_init_vars(&xy, &err, radius);
	while (xy.x >= xy.y)
	{
		temp.x = coords->x - xy.x - 1;
		while (++temp.x <= coords->x + xy.x)
		{
			temp.y = coords->y + xy.y;
			t_mlx_draw_pixel_alphap(img, &temp, color);
			temp.y = coords->y - xy.y;
			t_mlx_draw_pixel_alphap(img, &temp, color);
		}
		temp.x = coords->x - xy.y - 1;
		while (++temp.x <= coords->x + xy.y)
		{
			temp.y = coords->y + xy.x;
			t_mlx_draw_pixel_alphap(img, &temp, color);
			temp.y = coords->y - xy.x;
			t_mlx_draw_pixel_alphap(img, &temp, color);
		}
		t_mlx_circle_disk_update_err(&xy, &err);
	}
}
