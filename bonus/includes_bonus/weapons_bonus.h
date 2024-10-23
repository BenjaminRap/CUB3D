/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapons_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:09:22 by mhotting          #+#    #+#             */
/*   Updated: 2024/09/03 08:43:32 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPONS_BONUS_H
# define WEAPONS_BONUS_H

# include <sys/types.h>
# include <stdbool.h>

# include "mlx_api_bonus.h"

# define WEAPONS_H_RATIO					0.5f
# define NB_TOT_WEAPONS						8
# define IDX_W1_HAND						0
# define IDX_W2_PISTOL						1
# define IDX_W3_CHAINGUN					2
# define IDX_W4_BF_GUN						3
# define IDX_W5_PLASMA						4
# define IDX_W6_SHOTGUN						5
# define IDX_W7_ROCKET						6
# define IDX_W8_CHAINSAW					7

# define W1_HAND_LOAD_CAPACITY				0
# define W1_HAND_INITIAL_USES				0
# define W1_HAND_DAMAGES					5
# define W1_HAND_RANGE						1.05f
# define W1_HAND_COOLDOWN_EFFECT			0.5
# define W1_HAND_BULLET_COOLDOWN_EFFECT		0

# define W2_PISTOL_LOAD_CAPACITY			20
# define W2_PISTOL_INITIAL_USES				15
# define W2_PISTOL_DAMAGES					3
# define W2_PISTOL_RANGE					20.0f
# define W2_PISTOL_BULLET_SPEED				0
# define W2_PISTOL_COOLDOWN_EFFECT			0.3f
# define W2_PISTOL_BULLET_COOLDOWN_EFFECT	0

# define W3_CHAINGUN_LOAD_CAPACITY			100
# define W3_CHAINGUN_INITIAL_USES			50
# define W3_CHAINGUN_DAMAGES				1
# define W3_CHAINGUN_RANGE					6.0f
# define W3_CHAINGUN_BULLET_SPEED			25
# define W3_CHAINGUN_COOLDOWN_EFFECT		0
# define W3_CHAINGUN_BULLET_COOLDOWN_EFFECT	0

# define W4_BF_GUN_LOAD_CAPACITY			40
# define W4_BF_GUN_INITIAL_USES				30
# define W4_BF_GUN_DAMAGES					2
# define W4_BF_GUN_RANGE					8.0f
# define W4_BF_GUN_BULLET_SPEED				30
# define W4_BF_GUN_COOLDOWN_EFFECT			0
# define W4_BF_GUN_BULLET_COOLDOWN_EFFECT	0

# define W5_PLASMA_LOAD_CAPACITY			10
# define W5_PLASMA_INITIAL_USES				4
# define W5_PLASMA_DAMAGES					0
# define W5_PLASMA_RANGE					20.0f
# define W5_PLASMA_BULLET_SPEED				8.0f
# define W5_PLASMA_COOLDOWN_EFFECT			2.0f
# define W5_PLASMA_BULLET_COOLDOWN_EFFECT	3.0f

# define W6_SHOTGUN_LOAD_CAPACITY			10
# define W6_SHOTGUN_INITIAL_USES			8
# define W6_SHOTGUN_DAMAGES					8
# define W6_SHOTGUN_RANGE					3.0f
# define W6_SHOTGUN_BULLET_SPEED			25.0f
# define W6_SHOTGUN_COOLDOWN_EFFECT			1.0f
# define W6_SHOTGUN_BULLET_COOLDOWN_EFFECT	0.25f

# define W7_ROCKET_LOAD_CAPACITY			3
# define W7_ROCKET_INITIAL_USES				1
# define W7_ROCKET_DAMAGES					15
# define W7_ROCKET_RANGE					20.0f
# define W7_ROCKET_BULLET_SPEED				7.0f
# define W7_ROCKET_COOLDOWN_EFFECT			2.0f
# define W7_ROCKET_BULLET_COOLDOWN_EFFECT	0.5f

# define W8_CHAINSAW_LOAD_CAPACITY			0
# define W8_CHAINSAW_INITIAL_USES			0
# define W8_CHAINSAW_DAMAGES				3
# define W8_CHAINSAW_RANGE					1.05f
# define W8_CHAINSAW_BULLET_SPEED			0
# define W8_CHAINSAW_COOLDOWN_EFFECT		0
# define W8_CHAINSAW_BULLET_COOLDOWN_EFFECT	0

typedef struct s_weapon		t_weapon;
typedef struct s_list		t_list;
typedef struct s_game		t_game;
typedef struct s_bullet		t_bullet;
typedef struct s_animation	t_animation;

struct s_weapon
{
	t_image			*curr_frame;
	t_list			*curr_frame_link;
	t_image			*frame_default;
	t_list			*frames_action;
	t_image			*target;
	float			animation_update;
	size_t			load_capacity;
	size_t			remaining_use;
	size_t			damage;
	float			range;
	float			cooldown_curr;
	float			cooldown_effect;
	bool			is_limited;
	bool			is_use_continuous;
	bool			using;
	int				bullet_speed;
	float			bullet_cooldown_effect;
	t_animation		*bullet_live_anim;
	t_animation		*bullet_death_anim;
	t_mlx_coords	coords;
	t_mlx_coords	size;
	t_mlx_coords	target_coords;
	t_mlx_coords	target_size;
	void			(*action)(t_weapon *, t_game *);
	void			(*bullet_init)(t_bullet *, t_weapon *);
	void			(*bullet_use)(t_game *game, t_bullet *);
};

// Weapon functions
bool	init_weapons(t_game *game);
bool	init_resize_imgs(t_weapon weapons[NB_TOT_WEAPONS], t_mlx *mlx);
void	init_all_weapon_positions(t_weapon weapons[NB_TOT_WEAPONS], t_mlx *mlx);
void	update_weapon(t_weapon *weapon, t_game *game);
void	set_weapon_position(t_weapon *weapon, t_mlx *mlx);
void	set_weapon_target_position(t_weapon *weapon, t_mlx *mlx);
void	use_weapon(t_weapon *weapon, t_game *game);
void	stop_weapon(t_weapon *weapon);
void	weapon_update_cooldown(t_weapon *weapon, float delta_time);
void	reload_weapons_randomly(t_weapon weapons[NB_TOT_WEAPONS], \
			float reload_ratio, float reload_probability);

// Weapon initializers
void	init_w1_hand(t_weapon *weapon, t_game *game);
void	init_w2_pistol(t_weapon *weapon, t_game *game);
void	init_w3_chaingun(t_weapon *weapon, t_game *game);
void	init_w4_bf_gun(t_weapon *weapon, t_game *game);
void	init_w5_plasma(t_weapon *weapon, t_game *game);
void	init_w6_shotgun(t_weapon *weapon, t_game *game);
void	init_w7_rocket(t_weapon *weapon, t_game *game);
void	init_w8_chainsaw(t_weapon *weapon, t_game *game);

// Weapon callbacks
void	use_weapon_hand(t_weapon *weapon, t_game *game);
void	use_weapon_chainsaw(t_weapon *weapon, t_game *game);
void	use_weapon_no_bullet(t_weapon *weapon, t_game *game);
void	use_weapon_bullet(t_weapon *weapon, t_game *game);

#endif
