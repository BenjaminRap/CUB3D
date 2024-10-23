/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_identifier2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codekiwi <codekiwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:11:07 by root              #+#    #+#             */
/*   Updated: 2024/09/05 02:30:27 by codekiwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_bonus.h"

static void	init_weapons_identifier(char **identifier)
{
	identifier[IDX_TXTR_TARGET1] = ID_TEXTURE_TARGET1;
	identifier[IDX_TXTR_W1_HAND] = ID_TEXTURE_W1_HAND;
	identifier[IDX_TXTR_W1_PUNCH] = ID_TEXTURE_W1_PUNCH;
	identifier[IDX_TXTR_W2_PISTOL] = ID_TEXTURE_W2_PISTOL;
	identifier[IDX_TXTR_W3_CHAINGUN] = ID_TEXTURE_W3_CHAINGUN;
	identifier[IDX_TXTR_W4_BF_GUN] = ID_TEXTURE_W4_BF_GUN;
	identifier[IDX_TXTR_W5_PLASMA] = ID_TEXTURE_W5_PLASMA;
	identifier[IDX_TXTR_W6_SHOTGUN] = ID_TEXTURE_W6_SHOTGUN;
	identifier[IDX_TXTR_W7_ROCKET] = ID_TEXTURE_W7_ROCKET;
	identifier[IDX_TXTR_W8_CHAINSAW] = ID_TEXTURE_W8_CHAINSAW;
	identifier[IDX_TXTR_W_BUL_BASIC_LIVE] = ID_TEXTURE_W_BUL_BASIC_LIVE;
	identifier[IDX_TXTR_W_BUL_BASIC_DEATH] = ID_TEXTURE_W_BUL_BASIC_DEATH;
	identifier[IDX_TXTR_W_BUL_ROCKET_LIVE] = ID_TEXTURE_W_BUL_ROCKET_LIVE;
	identifier[IDX_TXTR_W_BUL_ROCKET_DEATH] = ID_TEXTURE_W_BUL_ROCKET_DEATH;
	identifier[IDX_TXTR_W_BUL_PLASMA_LIVE] = ID_TEXTURE_W_BUL_PLASMA_LIVE;
	identifier[IDX_TXTR_W_BUL_PLASMA_DEATH] = ID_TEXTURE_W_BUL_PLASMA_DEATH;
}

static void	init_hud_identifier(char **identifier)
{
	identifier[IDX_TXTR_HUD_BG] = ID_TEXTURE_HUD_BG;
	identifier[IDX_TXTR_HUD_HEALTH_LBL] = ID_TEXTURE_HUD_HEALTH_LBL;
	identifier[IDX_TXTR_HUD_WEAPON_LBL] = ID_TEXTURE_HUD_WEAPON_LBL;
}

void	init_identifier2(char **identifier)
{
	if (identifier == NULL)
		return ;
	init_weapons_identifier(identifier);
	init_hud_identifier(identifier);
}
