/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:00:39 by mhotting          #+#    #+#             */
/*   Updated: 2024/10/02 06:12:34 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>

#include "cub3d_bonus.h"

static void	*draw_thread_routine(void *param)
{
	t_draw_thread_arg	*thread_arg;

	if (param == NULL)
		return (NULL);
	thread_arg = (t_draw_thread_arg *) param;
	draw_walls_part(thread_arg->game, thread_arg->start, thread_arg->end);
	return (NULL);
}

bool	draw_walls(t_game *game)
{
	size_t	i;
	size_t	j;
	bool	error;

	error = false;
	i = 0;
	while (i < NB_DRAW_THREADS)
	{
		if (pthread_create(&game->threads[i], NULL, draw_thread_routine, \
			&game->draw_thread_args[i]) != 0)
		{
			error = true;
			break ;
		}
		i++;
	}
	j = 0;
	while (j < i)
	{
		if (pthread_join(game->threads[j], NULL))
			error = true;
		j++;
	}
	return (i == NB_DRAW_THREADS && !error);
}
