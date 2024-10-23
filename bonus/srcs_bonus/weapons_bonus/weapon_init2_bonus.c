/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_init2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:12:18 by mhotting          #+#    #+#             */
/*   Updated: 2024/08/31 16:49:54 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "libft.h"
#include "bullets_bonus.h"

void	init_w5_plasma(t_weapon *weapon, t_game *game)
{
	weapon->frame_default = \
		(t_image *) game->anim[IDX_TXTR_W5_PLASMA].textures->content;
	weapon->curr_frame = weapon->frame_default;
	weapon->curr_frame_link = NULL;
	weapon->frames_action = game->anim[IDX_TXTR_W5_PLASMA].textures->next;
	weapon->target = (t_image *) game->anim[IDX_TXTR_TARGET1].textures->content;
	weapon->animation_update = game->anim[IDX_TXTR_W5_PLASMA].wait;
	weapon->load_capacity = W5_PLASMA_LOAD_CAPACITY;
	weapon->remaining_use = W5_PLASMA_INITIAL_USES;
	weapon->damage = W5_PLASMA_DAMAGES;
	weapon->range = W5_PLASMA_RANGE;
	weapon->is_limited = true;
	weapon->is_use_continuous = false;
	weapon->action = use_weapon_bullet;
	weapon->using = false;
	weapon->bullet_speed = W5_PLASMA_BULLET_SPEED;
	weapon->bullet_init = player_gun_proj_init;
	weapon->bullet_live_anim = &game->anim[IDX_TXTR_W_BUL_PLASMA_LIVE];
	weapon->bullet_death_anim = &game->anim[IDX_TXTR_W_BUL_PLASMA_DEATH];
	weapon->bullet_use = player_basic_projectile_use;
	weapon->bullet_cooldown_effect = W5_PLASMA_BULLET_COOLDOWN_EFFECT;
	weapon->cooldown_curr = 0;
	weapon->cooldown_effect = W5_PLASMA_COOLDOWN_EFFECT;
}

void	init_w6_shotgun(t_weapon *weapon, t_game *game)
{
	weapon->frame_default = \
		(t_image *) game->anim[IDX_TXTR_W6_SHOTGUN].textures->content;
	weapon->curr_frame = weapon->frame_default;
	weapon->curr_frame_link = NULL;
	weapon->frames_action = game->anim[IDX_TXTR_W6_SHOTGUN].textures->next;
	weapon->target = (t_image *) game->anim[IDX_TXTR_TARGET1].textures->content;
	weapon->animation_update = game->anim[IDX_TXTR_W6_SHOTGUN].wait;
	weapon->load_capacity = W6_SHOTGUN_LOAD_CAPACITY;
	weapon->remaining_use = W6_SHOTGUN_INITIAL_USES;
	weapon->damage = W6_SHOTGUN_DAMAGES;
	weapon->range = W6_SHOTGUN_RANGE;
	weapon->is_limited = true;
	weapon->is_use_continuous = false;
	weapon->action = use_weapon_bullet;
	weapon->using = false;
	weapon->bullet_speed = W6_SHOTGUN_BULLET_SPEED;
	weapon->bullet_init = player_gun_proj_init;
	weapon->bullet_live_anim = &game->anim[IDX_TXTR_W_BUL_BASIC_LIVE];
	weapon->bullet_death_anim = &game->anim[IDX_TXTR_W_BUL_BASIC_DEATH];
	weapon->bullet_use = player_basic_projectile_use;
	weapon->bullet_cooldown_effect = W6_SHOTGUN_BULLET_COOLDOWN_EFFECT;
	weapon->cooldown_curr = 0;
	weapon->cooldown_effect = W6_SHOTGUN_COOLDOWN_EFFECT;
}

void	init_w7_rocket(t_weapon *weapon, t_game *game)
{
	weapon->frame_default = \
		(t_image *) game->anim[IDX_TXTR_W7_ROCKET].textures->content;
	weapon->curr_frame = weapon->frame_default;
	weapon->curr_frame_link = NULL;
	weapon->frames_action = game->anim[IDX_TXTR_W7_ROCKET].textures->next;
	weapon->target = (t_image *) game->anim[IDX_TXTR_TARGET1].textures->content;
	weapon->animation_update = game->anim[IDX_TXTR_W7_ROCKET].wait;
	weapon->load_capacity = W7_ROCKET_LOAD_CAPACITY;
	weapon->remaining_use = W7_ROCKET_INITIAL_USES;
	weapon->damage = W7_ROCKET_DAMAGES;
	weapon->range = W7_ROCKET_RANGE;
	weapon->is_limited = true;
	weapon->is_use_continuous = false;
	weapon->action = use_weapon_bullet;
	weapon->using = false;
	weapon->bullet_speed = W7_ROCKET_BULLET_SPEED;
	weapon->bullet_init = player_gun_proj_init;
	weapon->bullet_live_anim = &game->anim[IDX_TXTR_W_BUL_ROCKET_LIVE];
	weapon->bullet_death_anim = &game->anim[IDX_TXTR_W_BUL_ROCKET_DEATH];
	weapon->bullet_use = player_basic_projectile_use;
	weapon->bullet_cooldown_effect = W7_ROCKET_BULLET_COOLDOWN_EFFECT;
	weapon->cooldown_curr = 0;
	weapon->cooldown_effect = W7_ROCKET_COOLDOWN_EFFECT;
}

void	init_w8_chainsaw(t_weapon *weapon, t_game *game)
{
	weapon->frame_default = \
		(t_image *) game->anim[IDX_TXTR_W8_CHAINSAW].textures->content;
	weapon->curr_frame = weapon->frame_default;
	weapon->curr_frame_link = NULL;
	weapon->frames_action = game->anim[IDX_TXTR_W8_CHAINSAW].textures->next;
	weapon->target = NULL;
	weapon->animation_update = game->anim[IDX_TXTR_W8_CHAINSAW].wait;
	weapon->load_capacity = W8_CHAINSAW_LOAD_CAPACITY;
	weapon->remaining_use = W8_CHAINSAW_INITIAL_USES;
	weapon->damage = W8_CHAINSAW_DAMAGES;
	weapon->range = W8_CHAINSAW_RANGE;
	weapon->is_limited = false;
	weapon->is_use_continuous = true;
	weapon->action = use_weapon_chainsaw;
	weapon->using = false;
	weapon->bullet_speed = W8_CHAINSAW_BULLET_SPEED;
	weapon->bullet_init = NULL;
	weapon->bullet_live_anim = NULL;
	weapon->bullet_death_anim = NULL;
	weapon->bullet_use = NULL;
	weapon->bullet_cooldown_effect = W8_CHAINSAW_BULLET_COOLDOWN_EFFECT;
	weapon->cooldown_curr = 0;
	weapon->cooldown_effect = W8_CHAINSAW_COOLDOWN_EFFECT;
}
