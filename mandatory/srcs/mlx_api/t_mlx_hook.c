/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:02:47 by mhotting          #+#    #+#             */
/*   Updated: 2024/08/27 14:34:54 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_api.h"
#include "mlx.h"

/**
 * @brief Associates an event handling function to the given t_mlx instance
 * @param mlx The t_mlx instance
 * @param handler The handling function called when the event will occur
 * @param data The data which will be sent to the handler function when the
 * event will occur
 * @param hook_type The type of event
 * @return true on SUCCESS, false on ERROR
*/
bool	t_mlx_add_hook(
	t_mlx *mlx, int (*handler)(), void *data, enum e_hook_type hook_type
)
{
	if (mlx == NULL || handler == NULL)
		return (false);
	if (hook_type == HOOK_DESTROY)
		mlx_hook(mlx->mlx_win, MLX_ON_DESTROY, (1L << 3), handler, data);
	else if (hook_type == HOOK_KEY_RELEASE)
		mlx_hook(mlx->mlx_win, MLX_ON_KEYRELEASE, (1L << 0), handler, data);
	else if (hook_type == HOOK_KEY_PRESS)
		mlx_hook(mlx->mlx_win, MLX_ON_KEYPRESS, (1L << 1), handler, data);
	else if (hook_type == HOOK_MOUSE)
		mlx_mouse_hook(mlx->mlx_win, handler, data);
	else if (hook_type == HOOK_LOOP)
		mlx_loop_hook(mlx->mlx_ptr, handler, data);
	else
		return (false);
	mlx_loop_hook(mlx->mlx_ptr, handler, data);
	return (true);
}
