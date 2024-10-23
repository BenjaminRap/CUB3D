/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:36:36 by mhotting          #+#    #+#             */
/*   Updated: 2024/10/03 09:14:02 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "mlx_api.h"

/**
 * @brief Destroys properly a t_mlx instance
 * @param mlx The t_mlx instance to destroy
*/
void	t_mlx_destroy(t_mlx *mlx)
{
	if (mlx == NULL)
		return ;
	if (mlx->mlx_ptr != NULL && mlx->mlx_win != NULL)
		mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
	if (mlx->mlx_ptr != NULL && mlx->img1 != NULL)
		t_image_destroy(mlx->mlx_ptr, mlx->img1);
	if (mlx->mlx_ptr != NULL && mlx->img2 != NULL)
		t_image_destroy(mlx->mlx_ptr, mlx->img2);
	if (mlx->mlx_ptr != NULL)
	{
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
		mlx->mlx_ptr = NULL;
	}
	free(mlx->title);
}
