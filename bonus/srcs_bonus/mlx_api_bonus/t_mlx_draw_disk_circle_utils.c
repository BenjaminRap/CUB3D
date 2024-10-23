/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx_draw_disk_circle_utils.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 22:09:10 by codekiwi          #+#    #+#             */
/*   Updated: 2024/07/19 13:44:10 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_api_bonus.h"

void	t_mlx_circle_disk_update_err(t_mlx_coords *xy, int *err)
{
	if (*err <= 0)
	{
		xy->y += 1;
		*err += 2 * xy->y + 1;
	}
	if (*err > 0)
	{
		xy->x -= 1;
		*err -= 2 * xy->x + 1;
	}
}

void	t_mlx_circle_disk_init_vars(t_mlx_coords *xy, int *err, int radius)
{
	xy->x = radius;
	xy->y = 0;
	*err = 0;
}
