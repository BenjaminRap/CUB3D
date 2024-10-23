/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:36:55 by mhotting          #+#    #+#             */
/*   Updated: 2024/10/02 05:31:32 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d_bonus.h"
#include "mlx.h"
#include "error_bonus.h"

int	main(int argc, char **argv)
{
	t_game	game;

	(void)argv;
	if (argc != 1)
		return (error_print(ERR_PROG_ARGS), EXIT_FAILURE);
	ft_memset(&game, 0, sizeof(t_game));
	if (!read_maps(&game))
	{
		t_game_destroy(&game);
		return (EXIT_FAILURE);
	}
	game.map = &game.maps[0];
	if (!t_game_init(&game))
	{
		t_game_destroy(&game);
		return (EXIT_FAILURE);
	}
	mlx_loop(game.mlx.mlx_ptr);
	t_game_destroy(&game);
	return (0);
}
