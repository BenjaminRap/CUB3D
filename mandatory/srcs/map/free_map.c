/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:39:48 by brappo            #+#    #+#             */
/*   Updated: 2024/06/18 13:31:25 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"

void	free_map(t_map *map)
{
	if (map == NULL)
		return ;
	free_array(map->textures, MAP_NB_IDS, false);
	free_array(map->tiles, map->lines_count, true);
	map->tiles = NULL;
	free(map->lines_lengths);
	map->lines_lengths = NULL;
	get_next_line(-1);
}
