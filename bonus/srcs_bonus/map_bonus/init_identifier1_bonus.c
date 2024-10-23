/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_identifier1_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:11:07 by root              #+#    #+#             */
/*   Updated: 2024/09/12 06:15:17 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_bonus.h"

static void	init_world_identifier(char **identifier)
{
	identifier[IDX_TXTR_N] = ID_TEXTURE_NORTH;
	identifier[IDX_TXTR_S] = ID_TEXTURE_SOUTH;
	identifier[IDX_TXTR_W] = ID_TEXTURE_WEST;
	identifier[IDX_TXTR_E] = ID_TEXTURE_EAST;
	identifier[IDX_TXTR_FLOOR] = ID_TEXTURE_FLOOR;
	identifier[IDX_TXTR_CEIL] = ID_TEXTURE_CEILING;
	identifier[IDX_TXTR_DOOR] = ID_TEXTURE_DOOR;
	identifier[IDX_TXTR_SPRITE] = ID_TEXTURE_SPRITE;
	identifier[IDX_TXTR_SKY] = ID_TEXTURE_SKY;
	identifier[IDX_TXTR_LIGHT] = ID_TEXTURE_LIGHT;
}

static void	init_simple_enemies_identifier(char **identifier)
{
	identifier[IDX_TXTR_DEMON_WALK] = ID_TEXTURE_DEMON_WALK;
	identifier[IDX_TXTR_DEMON_PAIN] = ID_TEXTURE_DEMON_PAIN;
	identifier[IDX_TXTR_DEMON_ATTACK] = ID_TEXTURE_DEMON_ATTACK;
	identifier[IDX_TXTR_DEMON_DEATH] = ID_TEXTURE_DEMON_DEATH;
	identifier[IDX_TXTR_IMP_WALK] = ID_TEXTURE_IMP_WALK;
	identifier[IDX_TXTR_IMP_PAIN] = ID_TEXTURE_IMP_PAIN;
	identifier[IDX_TXTR_IMP_ATTACK] = ID_TEXTURE_IMP_ATTACK;
	identifier[IDX_TXTR_IMP_DEATH] = ID_TEXTURE_IMP_DEATH;
	identifier[IDX_TXTR_CACO_WALK] = ID_TEXTURE_CACO_WALK;
	identifier[IDX_TXTR_CACO_PAIN] = ID_TEXTURE_CACO_PAIN;
	identifier[IDX_TXTR_CACO_ATTACK] = ID_TEXTURE_CACO_ATTACK;
	identifier[IDX_TXTR_CACO_DEATH] = ID_TEXTURE_CACO_DEATH;
	identifier[IDX_TXTR_SERGEANT_WALK] = ID_TEXTURE_SERGEANT_WALK;
	identifier[IDX_TXTR_SERGEANT_PAIN] = ID_TEXTURE_SERGEANT_PAIN;
	identifier[IDX_TXTR_SERGEANT_ATTACK] = ID_TEXTURE_SERGEANT_ATTACK;
	identifier[IDX_TXTR_SERGEANT_DEATH] = ID_TEXTURE_SERGEANT_DEATH;
	identifier[IDX_TXTR_COMMANDO_WALK] = ID_TEXTURE_COMMANDO_WALK;
	identifier[IDX_TXTR_COMMANDO_PAIN] = ID_TEXTURE_COMMANDO_PAIN;
	identifier[IDX_TXTR_COMMANDO_ATTACK] = ID_TEXTURE_COMMANDO_ATTACK;
	identifier[IDX_TXTR_COMMANDO_DEATH] = ID_TEXTURE_COMMANDO_DEATH;
	identifier[IDX_TXTR_LOST_SOUL_WALK] = ID_TEXTURE_LOST_SOUL_WALK;
	identifier[IDX_TXTR_LOST_SOUL_DEATH] = ID_TEXTURE_LOST_SOUL_DEATH;
}

static void	init_enemies_identifier(char **identifier)
{
	identifier[IDX_TXTR_BOH_WALK] = ID_TEXTURE_BOH_WALK;
	identifier[IDX_TXTR_BOH_PAIN] = ID_TEXTURE_BOH_PAIN;
	identifier[IDX_TXTR_BOH_ATTACK] = ID_TEXTURE_BOH_ATTACK;
	identifier[IDX_TXTR_BOH_DEATH] = ID_TEXTURE_BOH_DEATH;
	identifier[IDX_TXTR_PAIN_ELEM_WALK] = ID_TEXTURE_PAIN_ELEM_WALK;
	identifier[IDX_TXTR_PAIN_ELEM_PAIN] = ID_TEXTURE_PAIN_ELEM_PAIN;
	identifier[IDX_TXTR_PAIN_ELEM_ATTACK] = ID_TEXTURE_PAIN_ELEM_ATTACK;
	identifier[IDX_TXTR_PAIN_ELEM_DEATH] = ID_TEXTURE_PAIN_ELEM_DEATH;
	identifier[IDX_TXTR_CYBER_WALK] = ID_TEXTURE_CYBER_WALK;
	identifier[IDX_TXTR_CYBER_PAIN] = ID_TEXTURE_CYBER_PAIN;
	identifier[IDX_TXTR_CYBER_ATTACK] = ID_TEXTURE_CYBER_ATTACK;
	identifier[IDX_TXTR_CYBER_DEATH] = ID_TEXTURE_CYBER_DEATH;
	identifier[IDX_TXTR_REV_WALK] = ID_TEXTURE_REV_WALK;
	identifier[IDX_TXTR_REV_PAIN] = ID_TEXTURE_REV_PAIN;
	identifier[IDX_TXTR_REV_PUNCH] = ID_TEXTURE_REV_PUNCH;
	identifier[IDX_TXTR_REV_SHOOT] = ID_TEXTURE_REV_SHOOT;
	identifier[IDX_TXTR_REV_DEATH] = ID_TEXTURE_REV_DEATH;
	identifier[IDX_TXTR_MANC_WALK] = ID_TEXTURE_MANC_WALK;
	identifier[IDX_TXTR_MANC_PAIN] = ID_TEXTURE_MANC_PAIN;
	identifier[IDX_TXTR_MANC_ATTACK] = ID_TEXTURE_MANC_ATTACK;
	identifier[IDX_TXTR_MANC_DEATH] = ID_TEXTURE_MANC_DEATH;
}

static void	init_bullets_identifier(char **identifier)
{
	identifier[IDX_TXTR_IMP_PROJ_LIVE] = ID_TEXTURE_IMP_PROJ_LIVE;
	identifier[IDX_TXTR_IMP_PROJ_DEATH] = ID_TEXTURE_IMP_PROJ_DEATH;
	identifier[IDX_TXTR_CACO_PROJ_LIVE] = ID_TEXTURE_CACO_PROJ_LIVE;
	identifier[IDX_TXTR_CACO_PROJ_DEATH] = ID_TEXTURE_CACO_PROJ_DEATH;
	identifier[IDX_TXTR_BOH_PROJ_LIVE] = ID_TEXTURE_BOH_PROJ_LIVE;
	identifier[IDX_TXTR_BOH_PROJ_DEATH] = ID_TEXTURE_BOH_PROJ_DEATH;
	identifier[IDX_TXTR_ROCKET_DEATH] = ID_TEXTURE_ROCKET_DEATH;
	identifier[IDX_TXTR_ROCKET_LIVE] = ID_TEXTURE_ROCKET_LIVE;
	identifier[IDX_TXTR_MANC_FIREBALL] = ID_TEXTURE_MANC_FIREBALL;
	identifier[IDX_TXTR_REV_PROJ_DEATH] = ID_TEXTURE_REV_PROJ_DEATH;
	identifier[IDX_TXTR_REV_PROJ_LIVE] = ID_TEXTURE_REV_PROJ_LIVE;
}

void	init_identifier(char **identifier)
{
	if (identifier == NULL)
		return ;
	init_world_identifier(identifier);
	init_enemies_identifier(identifier);
	init_simple_enemies_identifier(identifier);
	init_bullets_identifier(identifier);
	init_identifier2(identifier);
}
