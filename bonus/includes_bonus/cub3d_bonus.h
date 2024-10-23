/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:41:27 by mhotting          #+#    #+#             */
/*   Updated: 2024/10/02 22:42:42 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <pthread.h>

# include "config_bonus.h"
# include "player_bonus.h"
# include "ray_bonus.h"
# include "ui_bonus.h"
# include "radar_bonus.h"
# include "hud_bonus.h"
# include "map_bonus.h"

typedef struct s_game				t_game;
typedef struct s_draw_thread_arg	t_draw_thread_arg;
typedef struct s_mlx				t_mlx;
typedef struct s_column				t_column;
typedef struct s_sprite				t_sprite;
typedef struct s_door				t_door;
typedef struct s_list				t_list;
typedef enum e_game_state			t_game_state;

struct s_draw_thread_arg
{
	t_game	*game;
	size_t	start;
	size_t	end;
};

enum e_game_state
{
	STATE_GAMEOVER,
	STATE_GAMEWIN,
	STATE_HOME,
	STATE_LEVEL_SELECTION,
	STATE_PLAYING,
	STATE_PAUSE,
};

struct s_game
{
	t_game_state		state;
	t_mlx				mlx;
	t_player			player;
	ssize_t				curr_map_index;
	t_map				*map;
	t_map				maps[NB_MAPS];
	t_ray				rays[WIN_WIDTH];
	long				frame_time_usec;
	long				tick_last_frame;
	t_animation			*anim;
	t_animation			anims[NB_MAPS][MAP_NB_IDS];
	t_door				*last_door_seen;
	t_list				*sprites;
	t_list				*entities;
	t_list				*bullets;
	t_list				*last_entity_updated;
	t_weapon			weapons[NB_TOT_WEAPONS];
	t_game_uis			uis;
	bool				mouse_hidden;
	t_radar				radar;
	bool				map_opened;
	t_hud				hud;
	int					game_end_loop_count;
	pthread_t			threads[NB_DRAW_THREADS];
	t_draw_thread_arg	draw_thread_args[NB_DRAW_THREADS];
};

struct	s_column
{
	size_t			texture_start;
	int				texture_x;
	t_mlx_coords	coords;
	float			perceived_height;
	int				start;
	int				end;
	int				ground_start;
	int				ceiling_start;
	int				ranged_end;
	int				ranged_start;
	float			luminosity;
};

// Game functions
int		game_loop(t_game *game);
bool	t_game_init(t_game *game);
void	t_game_destroy(t_game *game);
void	t_game_destroy_and_exit(t_game *game);
void	game_pause_switch(t_game *game);
void	game_pause_close(t_game *game);
void	game_reach_level_selection(t_game *game);
void	game_reach_home(t_game *game);

// Render functions
bool	draw_walls(t_game *game);
void	draw_walls_part(t_game *game, size_t start, size_t end);
void	draw_texture_column(t_image *screen, t_column *column,
			t_image *texture);
void	render_all_sprites(t_game *game);
void	get_sprite_screen_pos(t_column *column, t_sprite *sprite, \
			t_game *game, float scale);
bool	is_sprite_aimed(t_sprite *sprite, int left_x);
void	draw_ground(t_column *column, int start, t_game *game, t_ray *ray);
void	draw_ceiling(t_column *column, int start, t_game *game, t_ray *ray);
int		get_offset(float perceived_height, t_player *player);
void	draw_sky(t_game *game);
bool	is_sky(t_vector *pixel_pos, t_map *map);

// Map selection
void	select_level1(t_game *game);
void	select_level2(t_game *game);
void	select_level3(t_game *game);
void	select_level4(t_game *game);
void	select_level5(t_game *game);
void	quit_level(t_game *game);
bool	game_load_map(t_game *game, size_t map_index);
void	game_unload_map(t_game *game);
void	reload_level(t_game *game);

#endif
