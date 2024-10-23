/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_destroy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:01:50 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/13 17:01:12 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"

/**
 * @brief Destroys the given t_game
 * @param game The structure to destroy
*/
void	t_game_destroy(t_game *game)
{
	size_t	index;

	if (game == NULL)
		return ;
	index = 0;
	while (index < MAP_NB_TEXTURES)
	{
		if (game->textures[index].ptr != NULL)
			mlx_destroy_image(game->mlx.mlx_ptr, game->textures[index].ptr);
		index++;
	}
	t_mlx_destroy(&game->mlx);
	free_map(&game->map);
}
