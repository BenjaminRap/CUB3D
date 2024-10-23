/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_init1_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:12:18 by mhotting          #+#    #+#             */
/*   Updated: 2024/08/31 01:09:54 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "libft.h"
#include "bullets_bonus.h"

void	init_w1_hand(t_weapon *weapon, t_game *game)
{
	weapon->frame_default = \
		(t_image *) game->anim[IDX_TXTR_W1_HAND].textures->content;
	weapon->curr_frame = weapon->frame_default;
	weapon->curr_frame_link = NULL;
	weapon->frames_action = game->anim[IDX_TXTR_W1_PUNCH].textures;
	weapon->target = NULL;
	weapon->animation_update = game->anim[IDX_TXTR_W1_HAND].wait;
	weapon->load_capacity = W1_HAND_LOAD_CAPACITY;
	weapon->remaining_use = W1_HAND_INITIAL_USES;
	weapon->damage = W1_HAND_DAMAGES;
	weapon->range = W1_HAND_RANGE;
	weapon->is_limited = false;
	weapon->is_use_continuous = false;
	weapon->action = use_weapon_hand;
	weapon->using = false;
	weapon->bullet_speed = 0;
	weapon->bullet_init = NULL;
	weapon->bullet_live_anim = NULL;
	weapon->bullet_death_anim = NULL;
	weapon->bullet_use = NULL;
	weapon->bullet_cooldown_effect = W1_HAND_BULLET_COOLDOWN_EFFECT;
	weapon->cooldown_curr = 0;
	weapon->cooldown_effect = W1_HAND_COOLDOWN_EFFECT;
}

void	init_w2_pistol(t_weapon *weapon, t_game *game)
{
	weapon->frame_default = \
		(t_image *) game->anim[IDX_TXTR_W2_PISTOL].textures->content;
	weapon->curr_frame = weapon->frame_default;
	weapon->curr_frame_link = NULL;
	weapon->frames_action = game->anim[IDX_TXTR_W2_PISTOL].textures->next;
	weapon->target = (t_image *) game->anim[IDX_TXTR_TARGET1].textures->content;
	weapon->animation_update = game->anim[IDX_TXTR_W2_PISTOL].wait;
	weapon->load_capacity = W2_PISTOL_LOAD_CAPACITY;
	weapon->remaining_use = W2_PISTOL_INITIAL_USES;
	weapon->damage = W2_PISTOL_DAMAGES;
	weapon->range = W2_PISTOL_RANGE;
	weapon->is_limited = true;
	weapon->is_use_continuous = false;
	weapon->action = use_weapon_no_bullet;
	weapon->using = false;
	weapon->bullet_speed = W2_PISTOL_BULLET_SPEED;
	weapon->bullet_init = NULL;
	weapon->bullet_live_anim = NULL;
	weapon->bullet_death_anim = NULL;
	weapon->bullet_use = NULL;
	weapon->bullet_cooldown_effect = W2_PISTOL_BULLET_COOLDOWN_EFFECT;
	weapon->cooldown_curr = 0;
	weapon->cooldown_effect = W2_PISTOL_COOLDOWN_EFFECT;
}

void	init_w3_chaingun(t_weapon *weapon, t_game *game)
{
	weapon->frame_default = \
		(t_image *) game->anim[IDX_TXTR_W3_CHAINGUN].textures->content;
	weapon->curr_frame = weapon->frame_default;
	weapon->curr_frame_link = NULL;
	weapon->frames_action = game->anim[IDX_TXTR_W3_CHAINGUN].textures->next;
	weapon->target = (t_image *) game->anim[IDX_TXTR_TARGET1].textures->content;
	weapon->animation_update = game->anim[IDX_TXTR_W3_CHAINGUN].wait;
	weapon->load_capacity = W3_CHAINGUN_LOAD_CAPACITY;
	weapon->remaining_use = W3_CHAINGUN_INITIAL_USES;
	weapon->damage = W3_CHAINGUN_DAMAGES;
	weapon->range = W3_CHAINGUN_RANGE;
	weapon->is_limited = true;
	weapon->is_use_continuous = true;
	weapon->action = use_weapon_no_bullet;
	weapon->using = false;
	weapon->bullet_speed = W3_CHAINGUN_BULLET_SPEED;
	weapon->bullet_init = NULL;
	weapon->bullet_live_anim = NULL;
	weapon->bullet_death_anim = NULL;
	weapon->bullet_use = NULL;
	weapon->bullet_cooldown_effect = W3_CHAINGUN_BULLET_COOLDOWN_EFFECT;
	weapon->cooldown_curr = 0;
	weapon->cooldown_effect = W3_CHAINGUN_COOLDOWN_EFFECT;
}

void	init_w4_bf_gun(t_weapon *weapon, t_game *game)
{
	weapon->frame_default = \
		(t_image *) game->anim[IDX_TXTR_W4_BF_GUN].textures->content;
	weapon->curr_frame = weapon->frame_default;
	weapon->curr_frame_link = NULL;
	weapon->frames_action = game->anim[IDX_TXTR_W4_BF_GUN].textures->next;
	weapon->target = (t_image *) game->anim[IDX_TXTR_TARGET1].textures->content;
	weapon->animation_update = game->anim[IDX_TXTR_W4_BF_GUN].wait;
	weapon->load_capacity = W4_BF_GUN_LOAD_CAPACITY;
	weapon->remaining_use = W4_BF_GUN_INITIAL_USES;
	weapon->damage = W4_BF_GUN_DAMAGES;
	weapon->range = W4_BF_GUN_RANGE;
	weapon->is_limited = true;
	weapon->is_use_continuous = true;
	weapon->action = use_weapon_bullet;
	weapon->using = false;
	weapon->bullet_speed = W4_BF_GUN_BULLET_SPEED;
	weapon->bullet_init = player_gun_proj_init;
	weapon->bullet_live_anim = &game->anim[IDX_TXTR_W_BUL_BASIC_LIVE];
	weapon->bullet_death_anim = &game->anim[IDX_TXTR_W_BUL_BASIC_DEATH];
	weapon->bullet_use = player_basic_projectile_use;
	weapon->bullet_cooldown_effect = W4_BF_GUN_BULLET_COOLDOWN_EFFECT;
	weapon->cooldown_curr = 0;
	weapon->cooldown_effect = W4_BF_GUN_COOLDOWN_EFFECT;
}
