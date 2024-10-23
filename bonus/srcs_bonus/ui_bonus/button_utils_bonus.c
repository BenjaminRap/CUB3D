/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:22:52 by mhotting          #+#    #+#             */
/*   Updated: 2024/08/27 14:22:02 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui_bonus.h"

void	draw_buttons(t_ui *ui, t_image *img)
{
	size_t		i;
	t_button	*btn;

	if (ui == NULL || img == NULL || ui->buttons == NULL)
		return ;
	i = 0;
	while (i < ui->nb_buttons)
	{
		btn = &ui->buttons[i];
		t_mlx_draw_rect_texture(img, &btn->pos, &btn->size, \
			btn->texture_active);
		i++;
	}
}

bool	is_over_button(t_button *btn, int x, int y)
{
	if (btn == NULL)
		return (false);
	return (
		x >= btn->pos.x && x <= btn->pos.x + btn->size.x
		&& y >= btn->pos.y && y <= btn->pos.y + btn->size.y
	);
}
