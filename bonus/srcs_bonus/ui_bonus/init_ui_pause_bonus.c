/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ui_pause_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:23:09 by mhotting          #+#    #+#             */
/*   Updated: 2024/09/05 10:23:02 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "libft.h"

static bool	init_ui_pause_btn1(
	t_ui *ui_pause,
	t_button *btn,
	void *mlx_ptr,
	t_image textures[UI_NB_TEXTURES]
)
{
	btn->size.x = UI_PAUSE_BTN1_W_RATIO * ui_pause->size.x;
	btn->size.y = UI_PAUSE_BTN1_H_RATIO * ui_pause->size.y;
	btn->pos.x = ui_pause->pos.x + (ui_pause->size.x / 2 - btn->size.x / 2);
	btn->pos.y = ui_pause->pos.y + 2 * ui_pause->size.y / 5;
	btn->texture_off = &textures[UI_TXTR_IDX_PAUSE_BTN_RESUME_OFF];
	btn->texture_on = &textures[UI_TXTR_IDX_PAUSE_BTN_RESUME_ON];
	if (
		!t_image_resize(mlx_ptr, btn->texture_off, &btn->size)
		|| !t_image_resize(mlx_ptr, btn->texture_on, &btn->size)
	)
		return (false);
	btn->texture_active = btn->texture_off;
	btn->callback = (void (*)(void *)) game_pause_close;
	return (true);
}

static bool	init_ui_pause_btn2(
	t_ui *ui_pause,
	t_button *btn,
	void *mlx_ptr,
	t_image textures[UI_NB_TEXTURES]
)
{
	btn->size.x = UI_PAUSE_BTN2_W_RATIO * ui_pause->size.x;
	btn->size.y = UI_PAUSE_BTN2_H_RATIO * ui_pause->size.y;
	btn->pos.x = ui_pause->pos.x + (ui_pause->size.x / 2 - btn->size.x / 2);
	btn->pos.y = ui_pause->pos.y + 3 * ui_pause->size.y / 5;
	btn->texture_off = &textures[UI_TXTR_IDX_PAUSE_BTN_QUIT_OFF];
	btn->texture_on = &textures[UI_TXTR_IDX_PAUSE_BTN_QUIT_ON];
	if (
		!t_image_resize(mlx_ptr, btn->texture_off, &btn->size)
		|| !t_image_resize(mlx_ptr, btn->texture_on, &btn->size)
	)
		return (false);
	btn->texture_active = btn->texture_off;
	btn->callback = (void (*)(void *)) quit_level;
	return (true);
}

static bool	init_ui_pause_buttons(
	t_ui *ui_pause,
	void *mlx,
	t_image textures[UI_NB_TEXTURES]
)
{
	ui_pause->buttons = (t_button *)ft_calloc(ui_pause->nb_buttons, \
		sizeof(t_button));
	if (ui_pause->buttons == NULL)
		return (false);
	if (
		!init_ui_pause_btn1(ui_pause, &ui_pause->buttons[0], mlx, textures)
		|| !init_ui_pause_btn2(ui_pause, &ui_pause->buttons[1], mlx, textures)
	)
	{
		free(ui_pause->buttons);
		ui_pause->buttons = NULL;
		return (false);
	}
	return (true);
}

static bool	init_ui_pause_labels(
	t_ui *ui_pause,
	void *mlx_ptr,
	t_image textures[UI_NB_TEXTURES]
)
{
	t_dimension	dim;

	ui_pause->labels = (t_label *)ft_calloc(ui_pause->nb_labels, \
		sizeof(t_label));
	if (ui_pause->labels == NULL)
		return (false);
	dim.size.x = UI_PAUSE_LBL_W_RATIO * ui_pause->size.x;
	dim.size.y = UI_PAUSE_LBL_H_RATIO * ui_pause->size.y;
	dim.coords.x = ui_pause->pos.x + (ui_pause->size.x / 2 - dim.size.x / 2);
	dim.coords.y = ui_pause->pos.y + ui_pause->size.y / 6;
	if (!init_label(&ui_pause->labels[0], &dim, \
		&textures[UI_TXTR_IDX_PAUSE_LABEL], mlx_ptr))
	{
		free(ui_pause->labels);
		ui_pause->labels = NULL;
		return (false);
	}
	return (true);
}

bool	init_ui_pause(
	t_ui *ui_pause,
	void *mlx_ptr,
	t_image textures[UI_NB_TEXTURES]
)
{
	if (ui_pause == NULL || mlx_ptr == NULL)
		return (false);
	ui_pause->texture = &textures[UI_TXTR_IDX_PAUSE_BG];
	ui_pause->size.x = (int)((float)WIN_WIDTH * UI_PAUSE_W_RATIO);
	ui_pause->size.y = (int)((float)WIN_HEIGHT * UI_PAUSE_H_RATIO);
	ui_pause->pos.x = (WIN_WIDTH - ui_pause->size.x) / 2;
	ui_pause->pos.y = (WIN_HEIGHT - ui_pause->size.y) / 2;
	ui_pause->nb_buttons = UI_PAUSE_NB_BTN;
	if (!init_ui_pause_buttons(ui_pause, mlx_ptr, textures))
	{
		destroy_ui(ui_pause, mlx_ptr);
		return (false);
	}
	ui_pause->nb_labels = UI_PAUSE_NB_LBL;
	if (!init_ui_pause_labels(ui_pause, mlx_ptr, textures))
	{
		destroy_ui(ui_pause, mlx_ptr);
		return (false);
	}
	return (true);
}
