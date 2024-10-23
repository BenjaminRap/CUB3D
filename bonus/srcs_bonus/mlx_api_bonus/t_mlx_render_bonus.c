/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx_render_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:49:37 by mhotting          #+#    #+#             */
/*   Updated: 2024/08/27 14:14:39 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_api_bonus.h"
#include "mlx.h"

/**
 * @brief Renders the buffer image of the given t_mlx instance
 * 
 * The current image will be replaced by the buffer image
 * Then the buffer image pointer will point to the old printed image
 * @param mlx The t_mlx instance to render
 * @return true on SUCCESS, false on ERROR
*/
bool	t_mlx_render(t_mlx *mlx)
{
	if (mlx == NULL || mlx->img_buff == NULL)
		return (false);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, \
		mlx->img_buff->ptr, 0, 0);
	if (mlx->img_buff == mlx->img1)
		mlx->img_buff = mlx->img2;
	else
		mlx->img_buff = mlx->img1;
	return (true);
}
