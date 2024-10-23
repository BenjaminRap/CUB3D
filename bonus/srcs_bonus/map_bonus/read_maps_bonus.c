/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_maps_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:41:17 by mhotting          #+#    #+#             */
/*   Updated: 2024/10/02 22:41:03 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "error_bonus.h"
#include "door_bonus.h"
#include "lights_bonus.h"

bool	read_maps(t_game *game)
{
	size_t		i;
	static char	*filenames[NB_MAPS] = {
		MAP0_PATH, MAP1_PATH, MAP2_PATH, MAP3_PATH, MAP4_PATH
	};

	if (game == NULL)
		return (error_print("ERR READ MAPS"), false);
	i = 0;
	while (i < NB_MAPS)
	{
		game->map = &game->maps[i];
		if (!read_map_tiles(game->map, filenames[i], game->anims[i]))
			return (false);
		if (!init_doors(game->map))
			return (false);
		if (!init_lights(game))
			return (false);
		i++;
	}
	game->map = NULL;
	return (true);
}
