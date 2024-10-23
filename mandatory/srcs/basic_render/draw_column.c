/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_column.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:23:55 by root              #+#    #+#             */
/*   Updated: 2024/09/04 10:41:55 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "cub3d.h"

static int	pixel_column_on_texture(t_ray *ray, int texture_width)
{
	int		column;
	float	texture_relative_position;
	double	temp;

	if (ray->is_vertical)
		texture_relative_position = modf(ray->intersection.y, &temp);
	else
		texture_relative_position = modf(ray->intersection.x, &temp);
	column = floorf(texture_relative_position * texture_width);
	return (column);
}

void	draw_texture_column(t_image *screen, t_column *column, int wall_end,
	t_image *texture)
{
	char	*color;
	int		texture_x;
	float	scale_y;
	char	*addr;
	float	texture_pos;

	texture_x = pixel_column_on_texture(column->ray, texture->width);
	scale_y = texture->height / column->perceived_height;
	addr = screen->addr + (column->coords.y * screen->line_len \
		+ column->coords.x * screen->bpp_factor);
	color = texture->addr + texture_x * (screen->bpp_factor);
	texture_pos = column->texture_start * scale_y;
	while (column->coords.y < wall_end)
	{
		*(unsigned int *)addr = *(unsigned int *)(color + \
			(int)texture_pos * texture->line_len);
		addr += screen->line_len;
		column->coords.y++;
		texture_pos += scale_y;
	}
}

void	draw_color_column(t_image *screen, t_mlx_coords *coords,
	unsigned int color, int end)
{
	char	*addr;

	addr = screen->addr + (coords->y * screen->line_len \
		+ coords->x * screen->bpp_factor);
	while (coords->y < end)
	{
		*(unsigned int *)addr = color;
		addr += screen->line_len;
		coords->y++;
	}
}
