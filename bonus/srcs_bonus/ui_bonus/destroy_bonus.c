/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codekiwi <codekiwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:46:29 by codekiwi          #+#    #+#             */
/*   Updated: 2024/09/05 01:10:26 by codekiwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	free_ui_textures(void *mlx_ptr, t_image textures[UI_NB_TEXTURES])
{
	size_t	i;

	if (textures == NULL)
		return ;
	i = 0;
	while (i < UI_NB_TEXTURES)
	{
		if (textures[i].ptr != NULL)
			t_image_destroy(mlx_ptr, &textures[i], false);
		i++;
	}
}

void	destroy_ui(t_ui *ui, void *mlx_ptr)
{
	if (ui == NULL || mlx_ptr == NULL)
		return ;
	if (ui->buttons != NULL)
	{
		free(ui->buttons);
		ui->buttons = NULL;
	}
	if (ui->labels != NULL)
	{
		free(ui->labels);
		ui->labels = NULL;
	}
}

void	destroy_game_uis(t_game *game, t_game_uis *uis)
{
	if (game == NULL || uis == NULL)
		return ;
	free_ui_textures(game->mlx.mlx_ptr, uis->textures);
	destroy_ui(&uis->pause, game->mlx.mlx_ptr);
	destroy_ui(&uis->game_over, game->mlx.mlx_ptr);
	destroy_ui(&uis->win, game->mlx.mlx_ptr);
	destroy_ui(&uis->home, game->mlx.mlx_ptr);
	destroy_ui(&uis->level_selection, game->mlx.mlx_ptr);
}
