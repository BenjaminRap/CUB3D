/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_bonus.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 09:21:09 by mhotting          #+#    #+#             */
/*   Updated: 2024/10/02 04:36:32 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UI_BONUS_H
# define UI_BONUS_H

# include "mlx_api_bonus.h"

# define UI_TEXTURES_PATH			"./assets/textures/ui/ui_textures_list.txt"
# define UI_NB_TEXTURES				37

# define UI_TXTR_PAUSE_BG					"UI_PAUSE_BG"
# define UI_TXTR_PAUSE_LABEL				"UI_PAUSE_LABEL"
# define UI_TXTR_PAUSE_BTN_RESUME_OFF		"UI_PAUSE_BTN_RESUME_OFF"
# define UI_TXTR_PAUSE_BTN_RESUME_ON		"UI_PAUSE_BTN_RESUME_ON"
# define UI_TXTR_PAUSE_BTN_QUIT_OFF			"UI_PAUSE_BTN_QUIT_OFF"
# define UI_TXTR_PAUSE_BTN_QUIT_ON			"UI_PAUSE_BTN_QUIT_ON"

# define UI_TXTR_GAMEOVER_BG				"UI_GAMEOVER_BG"
# define UI_TXTR_GAMEOVER_LABEL				"UI_GAMEOVER_LABEL"
# define UI_TXTR_GAMEOVER_BTN_QUIT_OFF		"UI_GAMEOVER_BTN_QUIT_OFF"
# define UI_TXTR_GAMEOVER_BTN_QUIT_ON		"UI_GAMEOVER_BTN_QUIT_ON"
# define UI_TXTR_GAMEOVER_BTN_RESTART_OFF	"UI_GAMEOVER_BTN_RESTART_OFF"
# define UI_TXTR_GAMEOVER_BTN_RESTART_ON	"UI_GAMEOVER_BTN_RESTART_ON"

# define UI_TXTR_WIN_BG						"UI_WIN_BG"
# define UI_TXTR_WIN_LABEL					"UI_WIN_LABEL"
# define UI_TXTR_WIN_TROPHY					"UI_WIN_TROPHY"
# define UI_TXTR_WIN_BTN_QUIT_OFF			"UI_WIN_BTN_QUIT_OFF"
# define UI_TXTR_WIN_BTN_QUIT_ON			"UI_WIN_BTN_QUIT_ON"

# define UI_TXTR_HOME_BG					"UI_HOME_BG"
# define UI_TXTR_HOME_LABEL					"UI_HOME_LABEL"
# define UI_TXTR_HOME_BTN_PLAY_OFF			"UI_HOME_BTN_PLAY_OFF"
# define UI_TXTR_HOME_BTN_PLAY_ON			"UI_HOME_BTN_PLAY_ON"
# define UI_TXTR_HOME_BTN_QUIT_OFF			"UI_HOME_BTN_QUIT_OFF"
# define UI_TXTR_HOME_BTN_QUIT_ON			"UI_HOME_BTN_QUIT_ON"

# define UI_TXTR_LVL_BG						"UI_LVL_BG"
# define UI_TXTR_LVL_LABEL					"UI_LVL_LABEL"
# define UI_TXTR_LVL_BTN_LVL1_OFF			"UI_LVL_BTN_LVL1_OFF"
# define UI_TXTR_LVL_BTN_LVL1_ON			"UI_LVL_BTN_LVL1_ON"
# define UI_TXTR_LVL_BTN_LVL2_OFF			"UI_LVL_BTN_LVL2_OFF"
# define UI_TXTR_LVL_BTN_LVL2_ON			"UI_LVL_BTN_LVL2_ON"
# define UI_TXTR_LVL_BTN_LVL3_OFF			"UI_LVL_BTN_LVL3_OFF"
# define UI_TXTR_LVL_BTN_LVL3_ON			"UI_LVL_BTN_LVL3_ON"
# define UI_TXTR_LVL_BTN_LVL4_OFF			"UI_LVL_BTN_LVL4_OFF"
# define UI_TXTR_LVL_BTN_LVL4_ON			"UI_LVL_BTN_LVL4_ON"
# define UI_TXTR_LVL_BTN_LVL5_OFF			"UI_LVL_BTN_LVL5_OFF"
# define UI_TXTR_LVL_BTN_LVL5_ON			"UI_LVL_BTN_LVL5_ON"
# define UI_TXTR_LVL_BTN_PREV_OFF			"UI_LVL_BTN_PREV_OFF"
# define UI_TXTR_LVL_BTN_PREV_ON			"UI_LVL_BTN_PREV_ON"

# define UI_TXTR_IDX_PAUSE_BG					0
# define UI_TXTR_IDX_PAUSE_LABEL				1
# define UI_TXTR_IDX_PAUSE_BTN_RESUME_OFF		2
# define UI_TXTR_IDX_PAUSE_BTN_RESUME_ON		3
# define UI_TXTR_IDX_PAUSE_BTN_QUIT_OFF			4
# define UI_TXTR_IDX_PAUSE_BTN_QUIT_ON			5

# define UI_TXTR_IDX_GAMEOVER_BG				6
# define UI_TXTR_IDX_GAMEOVER_LABEL				7
# define UI_TXTR_IDX_GAMEOVER_BTN_QUIT_OFF		8
# define UI_TXTR_IDX_GAMEOVER_BTN_QUIT_ON		9
# define UI_TXTR_IDX_GAMEOVER_BTN_RESTART_OFF	10
# define UI_TXTR_IDX_GAMEOVER_BTN_RESTART_ON	11

# define UI_TXTR_IDX_WIN_BG						12
# define UI_TXTR_IDX_WIN_LABEL					13
# define UI_TXTR_IDX_WIN_TROPHY					14
# define UI_TXTR_IDX_WIN_BTN_QUIT_OFF			15
# define UI_TXTR_IDX_WIN_BTN_QUIT_ON			16

# define UI_TXTR_IDX_HOME_BG					17
# define UI_TXTR_IDX_HOME_LABEL					18
# define UI_TXTR_IDX_HOME_BTN_PLAY_OFF			19
# define UI_TXTR_IDX_HOME_BTN_PLAY_ON			20
# define UI_TXTR_IDX_HOME_BTN_QUIT_OFF			21
# define UI_TXTR_IDX_HOME_BTN_QUIT_ON			22

# define UI_TXTR_IDX_LVL_BG						23
# define UI_TXTR_IDX_LVL_LABEL					24
# define UI_TXTR_IDX_LVL_BTN_LVL1_OFF			25
# define UI_TXTR_IDX_LVL_BTN_LVL1_ON			26
# define UI_TXTR_IDX_LVL_BTN_LVL2_OFF			27
# define UI_TXTR_IDX_LVL_BTN_LVL2_ON			28
# define UI_TXTR_IDX_LVL_BTN_LVL3_OFF			29
# define UI_TXTR_IDX_LVL_BTN_LVL3_ON			30
# define UI_TXTR_IDX_LVL_BTN_LVL4_OFF			31
# define UI_TXTR_IDX_LVL_BTN_LVL4_ON			32
# define UI_TXTR_IDX_LVL_BTN_LVL5_OFF			33
# define UI_TXTR_IDX_LVL_BTN_LVL5_ON			34
# define UI_TXTR_IDX_LVL_BTN_PREV_OFF			35
# define UI_TXTR_IDX_LVL_BTN_PREV_ON			36

# define UI_PAUSE_W_RATIO			0.5f
# define UI_PAUSE_H_RATIO			0.5f
# define UI_PAUSE_NB_LBL			1
# define UI_PAUSE_LBL_W_RATIO		0.3f
# define UI_PAUSE_LBL_H_RATIO		0.2f
# define UI_PAUSE_NB_BTN			2
# define UI_PAUSE_BTN1_W_RATIO		0.4f
# define UI_PAUSE_BTN1_H_RATIO		0.175f
# define UI_PAUSE_BTN2_W_RATIO		0.4f
# define UI_PAUSE_BTN2_H_RATIO		0.175f

# define UI_GAMEOVER_W_RATIO		0.5f
# define UI_GAMEOVER_H_RATIO		0.5f
# define UI_GAMEOVER_NB_LBL			1
# define UI_GAMEOVER_LBL_W_RATIO	0.75f
# define UI_GAMEOVER_LBL_H_RATIO	0.3f
# define UI_GAMEOVER_NB_BTN			2
# define UI_GAMEOVER_BTN_W_RATIO	0.4f
# define UI_GAMEOVER_BTN_H_RATIO	0.175f

# define UI_WIN_W_RATIO				0.5f
# define UI_WIN_H_RATIO				0.75f
# define UI_WIN_NB_LBL				2
# define UI_WIN_LBL_W_RATIO			0.75f
# define UI_WIN_LBL_H_RATIO			0.25f
# define UI_WIN_LBL_TROPHY_W_RATIO	0.25f
# define UI_WIN_LBL_TROPHY_H_RATIO	0.3f
# define UI_WIN_NB_BTN				1
# define UI_WIN_BTN_W_RATIO			0.4f
# define UI_WIN_BTN_H_RATIO			0.125f

# define UI_HOME_W_RATIO			1.0f
# define UI_HOME_H_RATIO			1.0f
# define UI_HOME_NB_LBL				1
# define UI_HOME_LBL_W_RATIO		0.39f
# define UI_HOME_LBL_H_RATIO		0.31f
# define UI_HOME_NB_BTN				2
# define UI_HOME_BTN_W_RATIO		0.21f
# define UI_HOME_BTN_H_RATIO		0.0925f

# define UI_LVL_W_RATIO				1.0f
# define UI_LVL_H_RATIO				1.0f
# define UI_LVL_NB_LBL				1
# define UI_LVL_LBL_W_RATIO			0.414f
# define UI_LVL_LBL_H_RATIO			0.1435f
# define UI_LVL_NB_BTN				6
# define UI_LVL_BTN_W_RATIO			0.21f
# define UI_LVL_BTN_H_RATIO			0.0925f

typedef struct s_game		t_game;
typedef struct s_game_uis	t_game_uis;
typedef struct s_ui			t_ui;
typedef struct s_button		t_button;
typedef struct s_label		t_label;
typedef struct s_list		t_list;

struct s_ui
{
	t_mlx_coords	pos;
	t_mlx_coords	size;
	t_image			*texture;
	size_t			nb_buttons;
	t_button		*buttons;
	size_t			nb_labels;
	t_label			*labels;
};

struct s_game_uis
{
	t_ui	pause;
	t_ui	game_over;
	t_ui	win;
	t_ui	home;
	t_ui	level_selection;
	t_image	textures[UI_NB_TEXTURES];
};

struct s_button
{
	t_mlx_coords	pos;
	t_mlx_coords	size;
	t_image			*texture_off;
	t_image			*texture_on;
	t_image			*texture_active;
	void			(*callback)(void *);
};

struct s_label
{
	t_mlx_coords	pos;
	t_mlx_coords	size;
	t_image			*texture;
};

// uis functions
bool	init_game_uis(t_game *game, t_game_uis *uis);
bool	init_uis_txtr_identifiers(char *identifiers[UI_NB_TEXTURES]);
bool	read_ui_elements(char *identifiers[UI_NB_TEXTURES], \
			t_image textures[UI_NB_TEXTURES], int fd, void *mlx_ptr);
void	free_ui_textures(void *mlx_ptr, t_image textures[UI_NB_TEXTURES]);
void	destroy_game_uis(t_game *game, t_game_uis *uis);

// ui functions
void	destroy_ui(t_ui *ui, void *mlx_ptr);
void	draw_ui(t_ui *ui, t_image *img);
void	disable_buttons_ui(t_ui *ui);
bool	init_ui_pause(t_ui *ui_pause, void *mlx_ptr, \
			t_image textures[UI_NB_TEXTURES]);
bool	init_ui_gameover(t_ui *ui_gameover, void *mlx_ptr, \
			t_image textures[UI_NB_TEXTURES]);
bool	init_ui_win(t_ui *ui_win, void *mlx_ptr, \
			t_image textures[UI_NB_TEXTURES]);
bool	init_ui_home(t_ui *ui_home, void *mlx_ptr, \
			t_image textures[UI_NB_TEXTURES]);
bool	init_ui_lvl(t_ui *ui_lvl, void *mlx_ptr, \
			t_image textures[UI_NB_TEXTURES]);
bool	init_ui_lvl_btn1(t_ui *ui_lvl, t_button *btn, void *mlx_ptr, \
			t_image textures[UI_NB_TEXTURES]);
bool	init_ui_lvl_btn2(t_ui *ui_lvl, t_button *btn, void *mlx_ptr, \
			t_image textures[UI_NB_TEXTURES]);
bool	init_ui_lvl_btn3(t_ui *ui_lvl, t_button *btn, void *mlx_ptr, \
			t_image textures[UI_NB_TEXTURES]);
bool	init_ui_lvl_btn4(t_ui *ui_lvl, t_button *btn, void *mlx_ptr, \
			t_image textures[UI_NB_TEXTURES]);
bool	init_ui_lvl_btn5(t_ui *ui_lvl, t_button *btn, void *mlx_ptr, \
			t_image textures[UI_NB_TEXTURES]);

// label functions
bool	init_label(t_label *label, t_dimension	*dim, t_image *texture, \
			void *mlx_ptr);
void	draw_labels(t_ui *ui, t_image *img);

// button functions
void	draw_buttons(t_ui *ui, t_image *img);
bool	is_over_button(t_button *btn, int x, int y);

#endif
