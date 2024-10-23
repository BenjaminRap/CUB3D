/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_resize_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:05:48 by mhotting          #+#    #+#             */
/*   Updated: 2024/10/02 06:27:56 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "weapons_bonus.h"

static bool	resize_weapon_img(t_image *img, int height, void *mlx_ptr)
{
	float			ratio;
	t_mlx_coords	size;

	ratio = (float) height / (float) img->height;
	size.x = ratio * img->width;
	size.y = ratio * img->height;
	return (t_image_resize(mlx_ptr, img, &size));
}

static bool	resize_weapon_imgs(t_weapon *weapon, t_mlx *mlx)
{
	int		t_height;
	t_list	*current;

	t_height = WEAPONS_H_RATIO * mlx->height;
	if (
		weapon->frame_default != NULL
		&& !resize_weapon_img(weapon->frame_default, t_height, mlx->mlx_ptr)
	)
		return (false);
	current = weapon->frames_action;
	while (current != NULL)
	{
		if (!resize_weapon_img((t_image *)current->content, t_height, \
			mlx->mlx_ptr))
			return (false);
		current = current->next;
	}
	return (true);
}

bool	init_resize_imgs(t_weapon weapons[NB_TOT_WEAPONS], t_mlx *mlx)
{
	size_t	i;

	i = 0;
	while (i < NB_TOT_WEAPONS)
	{
		if (!resize_weapon_imgs(&weapons[i], mlx))
			return (false);
		i++;
	}
	return (true);
}
