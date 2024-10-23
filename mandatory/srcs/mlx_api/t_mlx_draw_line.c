/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx_draw_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:04:21 by mhotting          #+#    #+#             */
/*   Updated: 2024/08/27 14:34:12 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_api.h"

/**
 * @brief Initializes the data for Bresenham algorithm
 * 
 * Two params to init:
 * 	- dxy will contain the absolute value of the x and y differences
 * 	- sxy will containt x and y evolution for each iteration
 * @param coords_start The starting point (x, y) coordinate
 * @param coords_end The line ending point (x, y) coordinate
 * @param dxy The dxy pointer whose values have to be intialized
 * @param sxy The sxy pointer whose values have to be intialized
*/
static void	t_mlx_draw_line_init(
	t_mlx_coords *coords_start, t_mlx_coords *coords_end,
	t_mlx_coords *dxy, t_mlx_coords *sxy
)
{
	dxy->x = abs(coords_end->x - coords_start->x);
	dxy->y = abs(coords_end->y - coords_start->y);
	sxy->x = -1;
	if (coords_start->x < coords_end->x)
		sxy->x = 1;
	sxy->y = -1;
	if (coords_start->y < coords_end->y)
		sxy->y = 1;
}

/**
 * @brief Checks if the line drawing is done
 * 
 * If sx.x is positive, it means that x was increasing and that curr x should
 * not be greater than end x
 * If sx.y is positive, it means that x was decreasing and that curr x should
 * not be lower than end x
 * The same principle applies to sx.y and y coordinate
 * @param coords_curr The current (x, y) coordinate
 * @param coords_end The line ending point (x, y) coordinate
 * @param sxy The (x, y) coordinate evolution
 * 
*/
static bool	t_mlx_draw_line_is_done(
	t_mlx_coords *coords_curr, t_mlx_coords *coords_end,
	t_mlx_coords *sxy
)
{
	return (
		(sxy->x == -1 && coords_curr->x < coords_end->x)
		|| (sxy->x == 1 && coords_curr->x > coords_end->x)
		|| (sxy->y == -1 && coords_curr->y < coords_end->y)
		|| (sxy->y == 1 && coords_curr->y > coords_end->y)
	);
}

/**
 * @brief Draws a line from coords_start to coords_end of the given color, onto
 * the given t_image
 * 
 * The Bresenham algorithm is used for drawing the line
 * @param img The image onto we will draw
 * @param coords_start The starting point coordinates of the line
 * @param coords_end The ending point coordinates of the line
 * @param color The color of the line
*/
void	t_mlx_draw_line(
	t_image *img,
	t_mlx_coords coords_start,
	t_mlx_coords coords_end,
	uint32_t color
)
{
	t_mlx_coords	dxy;
	t_mlx_coords	sxy;
	int				err;

	t_mlx_draw_line_init(&coords_start, &coords_end, &dxy, &sxy);
	err = dxy.x - dxy.y;
	while (!t_mlx_draw_line_is_done(&coords_start, &coords_end, &sxy))
	{
		t_mlx_draw_pixel(img, &coords_start, color);
		if (coords_start.x == coords_end.x && coords_start.y == coords_end.y)
			break ;
		if (2 * err > -dxy.y)
		{
			err -= dxy.y;
			coords_start.x += sxy.x;
		}
		if (2 * err < dxy.x)
		{
			err += dxy.x;
			coords_start.y += sxy.y;
		}
	}
}
