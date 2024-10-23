/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx_mouse_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:38:35 by mhotting          #+#    #+#             */
/*   Updated: 2024/10/02 22:22:06 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "mlx_api_bonus.h"

void	t_mlx_center_cursor(t_mlx *mlx)
{
	if (mlx == NULL || mlx->mlx_ptr == NULL || mlx->mlx_win == NULL)
		return ;
	mlx_mouse_move(mlx->mlx_ptr, mlx->mlx_win, mlx->width_half, \
		mlx->height_half);
}

void	t_mlx_mouse_show(t_mlx *mlx, bool *mouse_hidden)
{
	if (mlx == NULL || mouse_hidden == NULL || !*mouse_hidden)
		return ;
	mlx_mouse_show(mlx->mlx_ptr, mlx->mlx_win);
	t_mlx_center_cursor(mlx);
	*mouse_hidden = false;
}

void	t_mlx_mouse_hide(t_mlx *mlx, bool *mouse_hidden)
{
	if (mlx == NULL || mouse_hidden == NULL || *mouse_hidden)
		return ;
	mlx_mouse_hide(mlx->mlx_ptr, mlx->mlx_win);
	t_mlx_center_cursor(mlx);
	*mouse_hidden = true;
}
