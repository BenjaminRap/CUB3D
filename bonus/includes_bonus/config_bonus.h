/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 03:27:08 by brappo            #+#    #+#             */
/*   Updated: 2024/10/03 10:13:55 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_BONUS_H
# define CONFIG_BONUS_H

# define PI						3.14159265358
# define FPS					40
# define NB_DRAW_THREADS		16

# define WIN_TITLE				"Cub3D"
# define WIN_WIDTH				1920
# define WIN_HEIGHT				1000
# define MAX_DISTANCE			10
# define PAUSE_BG_DARK_FACTOR	0.4f

# define MAX_VISION_DISTANCE	10

# define GAMEOVER_DARKNESS		0.999999f
# define GAMEOVER_DARKNESS_LOOP	1000
# define GAMEWON_BRIGHTNESS		1.025f
# define GAMEWON_BRIGHT_LOOP	1000

# define NB_MAX_ENTITIES		100
# define NO_MAP_LOADED_INDEX	-1

#endif // !CONFIG_BONUS_H