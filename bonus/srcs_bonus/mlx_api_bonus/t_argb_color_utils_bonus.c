/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_argb_color_utils_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:39:25 by codekiwi          #+#    #+#             */
/*   Updated: 2024/09/11 10:22:01 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_api_bonus.h"

bool	set_color(unsigned int *result, int r, int g, int b)
{
	t_argb_color	color;

	if (r < 0 || g < 0 || b < 0
		|| r > 255 || g > 255 || b > 255)
		return (false);
	color.rgba.a = 255;
	color.rgba.r = r;
	color.rgba.g = g;
	color.rgba.b = b;
	*result = color.val;
	return (true);
}

void	multiply_color(unsigned int *result, float factor)
{
	uint8_t	*color;

	color = (uint8_t *)result;
	if (factor <= 0)
	{
		*result = 0xFF000000;
		return ;
	}
	color[0] *= factor;
	color[1] *= factor;
	color[2] *= factor;
}
