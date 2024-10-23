/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:11:53 by mhotting          #+#    #+#             */
/*   Updated: 2024/10/02 04:48:02 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_BONUS_H
# define SPRITE_BONUS_H

# include <stdlib.h>
# include <stdbool.h>

# include "vector_bonus.h"

typedef struct s_game		t_game;
typedef struct s_sprite		t_sprite;
typedef struct s_image		t_image;
typedef struct s_map		t_map;
typedef struct s_list		t_list;
typedef struct s_animation	t_animation;

struct	s_sprite
{
	t_vector	position;
	float		distance;
	t_list		*texture;
	t_animation	*animation;
	t_animation	*next_animation;
	size_t		height;
	float		frame_update_delta;
	bool		animate;
	bool		on_ground;
	bool		on_ceiling;
	bool		locked;
};

// Sprites functions
void		destroy_sprites(t_sprite ***sprites_ptr, size_t sprites_count);
void		get_sprites_distances(t_list *sprites, t_vector *pos);
float		compare_sprite_distance(void *a, void *b);
void		t_sprite_init(t_sprite *sprite, t_animation *animation,
				size_t height);
bool		init_sprites(t_game *game);
void		*add_sprite(t_game *game, float x, float y, char id);

#endif
