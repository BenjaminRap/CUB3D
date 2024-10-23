/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_elements_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 00:40:32 by codekiwi          #+#    #+#             */
/*   Updated: 2024/10/02 06:21:13 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "error_bonus.h"
#include "utils_bonus.h"
#include "ui_bonus.h"

static void	init_uis_ids1(char *identifiers[UI_NB_TEXTURES])
{
	identifiers[UI_TXTR_IDX_PAUSE_BG] = UI_TXTR_PAUSE_BG;
	identifiers[UI_TXTR_IDX_PAUSE_LABEL] = UI_TXTR_PAUSE_LABEL;
	identifiers[UI_TXTR_IDX_PAUSE_BTN_RESUME_OFF] = \
		UI_TXTR_PAUSE_BTN_RESUME_OFF;
	identifiers[UI_TXTR_IDX_PAUSE_BTN_RESUME_ON] = UI_TXTR_PAUSE_BTN_RESUME_ON;
	identifiers[UI_TXTR_IDX_PAUSE_BTN_QUIT_OFF] = UI_TXTR_PAUSE_BTN_QUIT_OFF;
	identifiers[UI_TXTR_IDX_PAUSE_BTN_QUIT_ON] = UI_TXTR_PAUSE_BTN_QUIT_ON;
	identifiers[UI_TXTR_IDX_GAMEOVER_BG] = UI_TXTR_GAMEOVER_BG;
	identifiers[UI_TXTR_IDX_GAMEOVER_LABEL] = UI_TXTR_GAMEOVER_LABEL;
	identifiers[UI_TXTR_IDX_GAMEOVER_BTN_QUIT_OFF] = \
		UI_TXTR_GAMEOVER_BTN_QUIT_OFF;
	identifiers[UI_TXTR_IDX_GAMEOVER_BTN_QUIT_ON] = \
		UI_TXTR_GAMEOVER_BTN_QUIT_ON;
	identifiers[UI_TXTR_IDX_GAMEOVER_BTN_RESTART_OFF] = \
		UI_TXTR_GAMEOVER_BTN_RESTART_OFF;
	identifiers[UI_TXTR_IDX_GAMEOVER_BTN_RESTART_ON] = \
		UI_TXTR_GAMEOVER_BTN_RESTART_ON;
	identifiers[UI_TXTR_IDX_WIN_BG] = UI_TXTR_WIN_BG;
	identifiers[UI_TXTR_IDX_WIN_LABEL] = UI_TXTR_WIN_LABEL;
	identifiers[UI_TXTR_IDX_WIN_TROPHY] = UI_TXTR_WIN_TROPHY;
	identifiers[UI_TXTR_IDX_WIN_BTN_QUIT_OFF] = UI_TXTR_WIN_BTN_QUIT_OFF;
	identifiers[UI_TXTR_IDX_WIN_BTN_QUIT_ON] = UI_TXTR_WIN_BTN_QUIT_ON;
	identifiers[UI_TXTR_IDX_HOME_BG] = UI_TXTR_HOME_BG;
	identifiers[UI_TXTR_IDX_HOME_LABEL] = UI_TXTR_HOME_LABEL;
	identifiers[UI_TXTR_IDX_HOME_BTN_PLAY_OFF] = UI_TXTR_HOME_BTN_PLAY_OFF;
}

static void	init_uis_ids2(char *identifiers[UI_NB_TEXTURES])
{
	identifiers[UI_TXTR_IDX_HOME_BTN_PLAY_ON] = UI_TXTR_HOME_BTN_PLAY_ON;
	identifiers[UI_TXTR_IDX_HOME_BTN_QUIT_OFF] = UI_TXTR_HOME_BTN_QUIT_OFF;
	identifiers[UI_TXTR_IDX_HOME_BTN_QUIT_ON] = UI_TXTR_HOME_BTN_QUIT_ON;
	identifiers[UI_TXTR_IDX_LVL_BG] = UI_TXTR_LVL_BG;
	identifiers[UI_TXTR_IDX_LVL_LABEL] = UI_TXTR_LVL_LABEL;
	identifiers[UI_TXTR_IDX_LVL_BTN_LVL1_OFF] = UI_TXTR_LVL_BTN_LVL1_OFF;
	identifiers[UI_TXTR_IDX_LVL_BTN_LVL1_ON] = UI_TXTR_LVL_BTN_LVL1_ON;
	identifiers[UI_TXTR_IDX_LVL_BTN_LVL2_OFF] = UI_TXTR_LVL_BTN_LVL2_OFF;
	identifiers[UI_TXTR_IDX_LVL_BTN_LVL2_ON] = UI_TXTR_LVL_BTN_LVL2_ON;
	identifiers[UI_TXTR_IDX_LVL_BTN_LVL3_OFF] = UI_TXTR_LVL_BTN_LVL3_OFF;
	identifiers[UI_TXTR_IDX_LVL_BTN_LVL3_ON] = UI_TXTR_LVL_BTN_LVL3_ON;
	identifiers[UI_TXTR_IDX_LVL_BTN_LVL4_OFF] = UI_TXTR_LVL_BTN_LVL4_OFF;
	identifiers[UI_TXTR_IDX_LVL_BTN_LVL4_ON] = UI_TXTR_LVL_BTN_LVL4_ON;
	identifiers[UI_TXTR_IDX_LVL_BTN_LVL5_OFF] = UI_TXTR_LVL_BTN_LVL5_OFF;
	identifiers[UI_TXTR_IDX_LVL_BTN_LVL5_ON] = UI_TXTR_LVL_BTN_LVL5_ON;
	identifiers[UI_TXTR_IDX_LVL_BTN_PREV_OFF] = UI_TXTR_LVL_BTN_PREV_OFF;
	identifiers[UI_TXTR_IDX_LVL_BTN_PREV_ON] = UI_TXTR_LVL_BTN_PREV_ON;
}

bool	init_uis_txtr_identifiers(char *identifiers[UI_NB_TEXTURES])
{
	if (identifiers == NULL)
		return (false);
	init_uis_ids1(identifiers);
	init_uis_ids2(identifiers);
	return (true);
}

static bool	read_ui_element(
	char *identifiers[UI_NB_TEXTURES],
	t_image textures[UI_NB_TEXTURES],
	char *line,
	void *mlx_ptr
)
{
	ssize_t	index;
	char	**split;

	split = ft_split(line, " ");
	if (array_length((void **) split) != 2)
	{
		ft_free_str_array(&split);
		return (error_print(ERR_UIS_READ_ELEMENT), false);
	}
	index = find_str_in_array(identifiers, split[0], UI_NB_TEXTURES);
	if (index == -1)
	{
		error_print_string(ERR_UIS_IDENTIFIER, split[0]);
		return (ft_free_str_array(&split), false);
	}
	if (!t_image_import_file(&textures[index], split[1], mlx_ptr, NULL))
	{
		error_print_string(ERR_UIS_IMG_INIT, split[1]);
		return (ft_free_str_array(&split), false);
	}
	ft_free_str_array(&split);
	identifiers[index] = NULL;
	return (true);
}

bool	read_ui_elements(
	char *identifiers[UI_NB_TEXTURES],
	t_image textures[UI_NB_TEXTURES],
	int fd,
	void *mlx_ptr
)
{
	char	*line;
	ssize_t	count;

	if (textures == NULL || fd < 0)
		return (error_print(ERR_UIS_CREATION), false);
	count = 0;
	while (count < UI_NB_TEXTURES)
	{
		line = get_next_line(fd);
		if (line == NULL)
			return (error_print(ERR_UIS_READ), false);
		else if (!ft_strcmp(line, "\n"))
		{
			free(line);
			continue ;
		}
		remove_last_breakline(line);
		if (!read_ui_element(identifiers, textures, line, mlx_ptr))
			return (free(line), false);
		free(line);
		count++;
	}
	return (true);
}
