/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:46:29 by codekiwi          #+#    #+#             */
/*   Updated: 2024/10/02 06:17:48 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

#include "cub3d_bonus.h"
#include "libft.h"
#include "error_bonus.h"

static bool	uis_init_textures(t_game *game, t_game_uis *uis)
{
	char	*identifiers[UI_NB_TEXTURES];
	int		fd;

	if (game == NULL || uis == NULL || game->mlx.mlx_ptr == NULL)
		return (error_print(ERR_UIS_CREATION), false);
	ft_bzero(uis, sizeof(t_game_uis));
	if (!init_uis_txtr_identifiers(identifiers))
		return (error_print(ERR_UIS_IDS_CREATION), false);
	fd = open(UI_TEXTURES_PATH, O_RDONLY);
	if (fd == -1)
		return (error_print(ERR_UIS_IDS_CREATION), false);
	if (!read_ui_elements(identifiers, uis->textures, fd, game->mlx.mlx_ptr))
	{
		free_ui_textures(game->mlx.mlx_ptr, uis->textures);
		close(fd);
		return (false);
	}
	close(fd);
	return (true);
}

bool	init_game_uis(t_game *game, t_game_uis *uis)
{
	if (game == NULL || uis == NULL)
		return (error_print(ERR_UIS_CREATION), false);
	if (!uis_init_textures(game, uis))
		return (false);
	if (
		!init_ui_pause(&uis->pause, game->mlx.mlx_ptr, uis->textures)
		|| !init_ui_gameover(&uis->game_over, game->mlx.mlx_ptr, uis->textures)
		|| !init_ui_win(&uis->win, game->mlx.mlx_ptr, uis->textures)
		|| !init_ui_home(&uis->home, game->mlx.mlx_ptr, uis->textures)
		|| !init_ui_lvl(&uis->level_selection, game->mlx.mlx_ptr, uis->textures)
	)
	{
		free_ui_textures(game->mlx.mlx_ptr, uis->textures);
		return (error_print(ERR_UI_CREATION), false);
	}
	return (true);
}
