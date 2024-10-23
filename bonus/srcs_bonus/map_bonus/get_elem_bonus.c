/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elem_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:22:06 by root              #+#    #+#             */
/*   Updated: 2024/09/02 17:01:18 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "libft.h"

bool	get_elem_into_list(t_game *game, t_list **dest, char *ids,
	void *add_elem(t_game *, float, float, char))
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < game->map->lines_count)
	{
		x = 0 ;
		while (x < game->map->lines_lengths[y])
		{
			if (ft_strchr(ids, game->map->tiles[y][x]))
			{
				if (!add_elem(game, x + 0.5, y + 0.5, game->map->tiles[y][x]))
				{
					ft_lstclear(dest, free);
					return (false);
				}
			}
			x++;
		}
		y++;
	}
	return (true);
}
