/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_home_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:47:03 by mhotting          #+#    #+#             */
/*   Updated: 2024/09/03 14:52:30 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	game_reach_home(t_game *game)
{
	if (game == NULL)
		return ;
	game->state = STATE_HOME;
}
