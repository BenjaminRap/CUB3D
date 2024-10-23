/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:02:42 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/13 17:00:05 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "event_handlers.h"
#include "libft.h"

static bool	init_textures(t_game *game)
{
	size_t	index;
	char	*filename;

	index = 0;
	while (index < MAP_NB_TEXTURES)
	{
		filename = game->map.textures[index];
		if (filename == NULL || filename[0] == '\0')
			return (error_print(ERR_MISSING_TEXTURES), false);
		if (!check_extension(filename, ".xpm"))
			return (error_print(ERR_TEXTURE_EXTENSION), false);
		if (!t_image_import_file(&game->textures[index], filename,
				game->mlx.mlx_ptr))
			return (error_print(ERR_INIT_TEXTURES), false);
		index++;
	}
	return (true);
}

static bool	set_color_components(unsigned int *color, char *r, char *g, char *b)
{
	int		r_value;
	int		g_value;
	int		b_value;
	bool	error;

	if (!is_number(r) || !is_number(g) || !is_number(b))
		return (error_print(ERR_COLOR_NAN), false);
	r_value = ft_atoi(r);
	g_value = ft_atoi(g);
	b_value = ft_atoi(b);
	if (ft_strlen(r) > 3 || ft_strlen(g) > 3 || ft_strlen(b) > 3)
		return (error_print(ERR_COLOR_RANGE), false);
	error = !set_color(color, r_value, g_value, b_value);
	if (error)
		error_print(ERR_COLOR_RANGE);
	return (!error);
}

static bool	init_color(unsigned int *color_result, char *color)
{
	char			**components;
	bool			error;
	size_t			length;

	components = ft_split(color, ",");
	if (components == NULL)
		return (NULL);
	length = array_length((void **)components);
	if (length != 3)
	{
		free_array(components, length, true);
		if (length > 3)
			return (error_print(ERR_TOO_MUCH_COLOR), false);
		else
			return (error_print(ERR_MISSING_COLOR), false);
	}
	error = !set_color_components(color_result, components[0], components[1],
			components[2]);
	free_array(components, 3, true);
	return (!error);
}

/**
 * @brief Initializes the given t_game
 * @param game The structure to init
 * @return true on SUCCESS, false on ERROR
*/
bool	t_game_init(t_game *game)
{
	if (game == NULL)
		return (false);
	if (!t_player_init(&game->player, &game->map))
		return (false);
	if (!init_color(&game->ceiling_color, game->map.textures[4])
		|| !init_color(&game->ground_color, game->map.textures[5]))
		return (false);
	if (!t_mlx_init(&game->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE))
		return (false);
	if (!init_textures(game))
		return (false);
	if (!t_mlx_launch(&game->mlx))
		return (false);
	if (!add_event_handlers(game))
		return (error_print(ERR_HOOKS), false);
	return (true);
}
