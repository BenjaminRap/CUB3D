/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:36:13 by mhotting          #+#    #+#             */
/*   Updated: 2024/10/02 06:21:38 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui_bonus.h"

void	draw_ui(t_ui *ui, t_image *img)
{
	if (ui == NULL || img == NULL)
		return ;
	t_mlx_draw_rect_texture(img, &ui->pos, &ui->size, ui->texture);
	draw_labels(ui, img);
	draw_buttons(ui, img);
}

void	disable_buttons_ui(t_ui *ui)
{
	size_t		i;

	if (ui == NULL)
		return ;
	i = 0;
	while (i < ui->nb_buttons)
	{
		ui->buttons[i].texture_active = ui->buttons[i].texture_off;
		i++;
	}
}
