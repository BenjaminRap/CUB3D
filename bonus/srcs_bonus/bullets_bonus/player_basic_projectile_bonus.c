/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_basic_projectile_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 10:50:01 by brappo            #+#    #+#             */
/*   Updated: 2024/10/02 03:55:54 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprite_bonus.h"
#include "bullets_bonus.h"
#include "config_bonus.h"
#include "weapons_bonus.h"

void	player_gun_proj_init(
	t_bullet *bullet,
	t_weapon *weapon
)
{
	if (bullet == NULL || weapon == NULL)
		return ;
	t_sprite_init(bullet->sprite, weapon->bullet_live_anim, WIN_HEIGHT);
	bullet->player_protected = true;
	bullet->use = weapon->bullet_use;
	bullet->speed = weapon->bullet_speed;
	bullet->damage = weapon->damage;
	bullet->animation = weapon->bullet_death_anim;
	bullet->cooldown_time = weapon->bullet_cooldown_effect;
}
