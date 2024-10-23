/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offset_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 22:19:07 by brappo            #+#    #+#             */
/*   Updated: 2024/10/02 06:14:45 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config_bonus.h"
#include "player_bonus.h"

/**
 * The height offset is relative the the wall/sprite perceived height, when the
 * camera go up, the start of each wall gets closer, while the end of each wall
 * gets further.
 * It's the inverse behaviour when the camera go down.
 * @brief Calculate the offset of a column, due to the camera height.
 * @param perceived_height The perceived height of the wall or sprite.
 * @param camera_y_diff The diffence between the camera height and the middle
 * of the screen.
 */
static int	get_height_offset(float perceived_height, int camera_y_diff)
{
	return (camera_y_diff - camera_y_diff * perceived_height / WIN_HEIGHT);
}

/**
 * @brief Return the offset due to the camera rotation and camera height
 * @param perceived_height The perceived height of the wall or sprite.
 * @return The offset to apply yo the wall and end position
 */
int	get_offset(float perceived_height, t_player *player)
{
	int	height_offset;

	height_offset = get_height_offset(perceived_height, player->camera_y_diff);
	return (height_offset + player->orientation.y);
}
