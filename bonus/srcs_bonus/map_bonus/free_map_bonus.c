/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:39:48 by brappo            #+#    #+#             */
/*   Updated: 2024/10/02 22:40:33 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "utils_bonus.h"
#include "map_bonus.h"
#include "lights_bonus.h"

void	free_map(t_map *map)
{
	if (map == NULL)
		return ;
	if (map->doors != NULL)
	{
		free(map->doors);
		map->doors = NULL;
	}
	free_lights(&map->lights, map->lights_count);
	free_array(map->textures, MAP_NB_IDS, false);
	ft_free_str_array(&map->tiles);
	ft_free_str_array(&map->tiles_save);
	free(map->lines_lengths);
	map->lines_lengths = NULL;
}

void	free_maps(t_map maps[NB_MAPS])
{
	size_t	i;

	if (maps == NULL)
		return ;
	i = 0;
	while (i < NB_MAPS)
	{
		free_map(&maps[i]);
		i++;
	}
	get_next_line(-1);
}
