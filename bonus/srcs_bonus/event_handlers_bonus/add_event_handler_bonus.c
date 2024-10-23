/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_event_handler_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:25:06 by mhotting          #+#    #+#             */
/*   Updated: 2024/10/02 03:38:55 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "event_handlers_bonus.h"
#include "error_bonus.h"

/**
 * @brief Adds all the event handlers to the given t_game structure
 * 
 * Adds loop, destroy and keyboard handlers
 * @param data The t_game instance which needs the handlers
 * @return true on SUCCESS, false on ERROR
*/
bool	add_event_handlers(t_game *data)
{
	if (data == NULL)
		return (error_print(ERR_HOOKS), false);
	if (
		!t_mlx_add_hook(&data->mlx, destroy_handler, data, HOOK_DESTROY)
		|| !t_mlx_add_hook(&data->mlx, key_release_handler, data, \
			HOOK_KEY_RELEASE)
		|| !t_mlx_add_hook(&data->mlx, key_press_handler, data, \
			HOOK_KEY_PRESS)
		|| !t_mlx_add_hook(&data->mlx, mouse_move_handler, data, \
			HOOK_MOUSE_MOVE)
		|| !t_mlx_add_hook(&data->mlx, mouse_press_handler, data, \
			HOOK_MOUSE_PRESS)
		|| !t_mlx_add_hook(&data->mlx, mouse_release_handler, data, \
			HOOK_MOUSE_RELEASE)
		|| !t_mlx_add_hook(&data->mlx, game_loop, data, HOOK_LOOP)
	)
		return (error_print(ERR_HOOKS), false);
	return (true);
}
