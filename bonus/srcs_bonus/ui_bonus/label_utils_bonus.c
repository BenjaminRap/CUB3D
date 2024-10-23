/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:22:52 by mhotting          #+#    #+#             */
/*   Updated: 2024/08/27 15:29:08 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui_bonus.h"

bool	init_label(
	t_label *label,
	t_dimension	*dim,
	t_image *texture,
	void *mlx_ptr
)
{
	if (label == NULL || dim == NULL || texture == NULL || mlx_ptr == NULL)
		return (false);
	label->pos.x = dim->coords.x;
	label->pos.y = dim->coords.y;
	label->size.x = dim->size.x;
	label->size.y = dim->size.y;
	label->texture = texture;
	if (!t_image_resize(mlx_ptr, label->texture, &label->size))
		return (false);
	return (true);
}

void	draw_labels(t_ui *ui, t_image *img)
{
	size_t	i;
	t_label	*lbl;

	if (ui == NULL || img == NULL || ui->labels == NULL)
		return ;
	i = 0;
	while (i < ui->nb_labels)
	{
		lbl = &ui->labels[i];
		t_mlx_draw_rect_texture(img, &lbl->pos, &lbl->size, lbl->texture);
		i++;
	}
}
