/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player_weapon_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:25:35 by brappo            #+#    #+#             */
/*   Updated: 2024/10/02 05:54:02 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_bonus.h"

static void	update_player_weapon_switching(
	t_player_weapon *weapon_info,
	t_weapon *weapon
)
{
	if (weapon_info->frame_update_delta < PLAYER_WEAPON_V_MOVE_UPDATE)
		return ;
	weapon_info->frame_update_delta = 0;
	if (weapon_info->weapon_state == WEAPON_STATE_HOLSTERING)
	{
		weapon_info->draw_offset.y += weapon_info->switch_vert_offset;
		if (weapon_info->draw_offset.y >= weapon->curr_frame->height)
		{
			weapon_info->weapon_state = WEAPON_STATE_DRAWING;
			weapon_info->curr_weapon_index = weapon_info->next_weapon_index;
			weapon_info->curr_weapon = \
				weapon_info->weapons[weapon_info->curr_weapon_index];
		}
	}
	if (weapon_info->weapon_state == WEAPON_STATE_DRAWING)
	{
		weapon_info->draw_offset.y -= weapon_info->switch_vert_offset;
		if (weapon_info->draw_offset.y <= 0)
			weapon_info->weapon_state = WEAPON_STATE_IDLE;
	}
}

static void	update_player_weapon_using(
	t_player_weapon *weapon_info,
	t_weapon *weapon,
	t_game *game
)
{
	if (weapon_info->frame_update_delta < weapon->animation_update)
		return ;
	weapon_info->frame_update_delta = 0;
	update_weapon(weapon, game);
	if (weapon->curr_frame == weapon->frame_default)
		weapon_info->weapon_state = WEAPON_STATE_IDLE;
}

static void	update_player_weapon_h_offset(
	t_player_weapon *weapon_info,
	bool is_player_walking,
	float delta_time
)
{
	if (!is_player_walking || weapon_info->weapon_state == WEAPON_STATE_USING)
	{
		weapon_info->frame_update_delta_h_move = 0;
		weapon_info->draw_offset.x = 0;
	}
	else
	{
		weapon_info->frame_update_delta_h_move += delta_time;
		if (weapon_info->frame_update_delta_h_move < \
			PLAYER_WEAPON_H_MOVE_UPDATE)
			return ;
		weapon_info->frame_update_delta_h_move = 0;
		weapon_info->draw_offset.x += \
			weapon_info->draw_offset_sign * PLAYER_WEAPON_H_OFFSET_STEP;
		if (abs(weapon_info->draw_offset.x) >= PLAYER_WEAPON_H_OFFSET_MAX)
			weapon_info->draw_offset_sign *= -1;
	}
}

static void	update_player_weapon_cooldowns(t_weapon	**weapons, float delta_time)
{
	size_t	i;

	i = 0;
	while (i < NB_TOT_WEAPONS)
	{
		weapon_update_cooldown(weapons[i], delta_time);
		i++;
	}
}

void	update_player_weapon(
	t_player_weapon *weapon_info,
	bool is_player_walking,
	t_game *game,
	float delta_time
)
{
	update_player_weapon_cooldowns(weapon_info->weapons, delta_time);
	weapon_info->frame_update_delta += delta_time;
	if (weapon_info->weapon_state == WEAPON_STATE_USING)
		update_player_weapon_using(weapon_info, weapon_info->curr_weapon, game);
	else if (
		weapon_info->weapon_state == WEAPON_STATE_HOLSTERING
		|| weapon_info->weapon_state == WEAPON_STATE_DRAWING
	)
		update_player_weapon_switching(weapon_info, weapon_info->curr_weapon);
	update_player_weapon_h_offset(weapon_info, is_player_walking, delta_time);
}
