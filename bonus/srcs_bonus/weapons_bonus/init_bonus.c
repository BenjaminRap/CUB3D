/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:12:18 by mhotting          #+#    #+#             */
/*   Updated: 2024/10/02 06:26:37 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "error_bonus.h"

bool	init_weapons(t_game *game)
{
	if (game == NULL)
		return (error_print(ERR_WEAPONS_CREATION), false);
	init_w1_hand(&game->weapons[IDX_W1_HAND], game);
	init_w2_pistol(&game->weapons[IDX_W2_PISTOL], game);
	init_w3_chaingun(&game->weapons[IDX_W3_CHAINGUN], game);
	init_w4_bf_gun(&game->weapons[IDX_W4_BF_GUN], game);
	init_w5_plasma(&game->weapons[IDX_W5_PLASMA], game);
	init_w6_shotgun(&game->weapons[IDX_W6_SHOTGUN], game);
	init_w7_rocket(&game->weapons[IDX_W7_ROCKET], game);
	init_w8_chainsaw(&game->weapons[IDX_W8_CHAINSAW], game);
	if (!init_resize_imgs(game->weapons, &game->mlx))
		return (error_print(ERR_WEAPONS_RESIZE), false);
	init_all_weapon_positions(game->weapons, &game->mlx);
	return (true);
}
