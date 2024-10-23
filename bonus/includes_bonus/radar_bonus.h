/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radar_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 18:52:04 by codekiwi          #+#    #+#             */
/*   Updated: 2024/10/02 06:01:57 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RADAR_BONUS_H
# define RADAR_BONUS_H

# include <stdbool.h>

# include "mlx_api_bonus.h"

# define RADAR_SIZE_RATIO		10.0f
# define RADAR_ROT_SENSIBILIY	0.0001f
# define RADAR_OFFSET			10
# define RADAR_NB_TILES			17

# define RAD_COL_TRANSPARENT	0xFF000000
# define RAD_COL_BG				0x002801
# define RAD_COL_SPACE			0x002801
# define RAD_COL_WALL			0x09BB17
# define RAD_COL_TILE			0x006700
# define RAD_COL_DOOR1			0x00FF00
# define RAD_COL_DOOR2			0x006700
# define RAD_COL_PLAYER			0xFFFF55
# define RAD_COL_ENTITY			0xFF2222

typedef struct s_game	t_game;
typedef struct s_radar	t_radar;
typedef struct s_map	t_map;
typedef struct s_player	t_player;

struct s_radar
{
	t_mlx_coords	coords;
	t_mlx_coords	center;
	t_mlx_coords	size;
	int				draw_offset;
	int				radius;
	t_image			*img;
	t_image			*img2;
	float			orientation;
	uint32_t		color_border;
	char			**tiles;
	int				nb_tiles;
	bool			needs_update;
	int				tile_size;
	int				radius_element;
};

// Radar functions
bool	init_radar(t_radar *radar, t_mlx *mlx);
void	destroy_radar(t_radar *radar, void *mlx_ptr);
void	draw_radar(t_game *game, t_radar *radar, t_mlx *mlx);
void	update_tiles(t_map *map, t_radar *radar, t_player *player);
void	draw_radar_rotate(t_radar *radar);

#endif
