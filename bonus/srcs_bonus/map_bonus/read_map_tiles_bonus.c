/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_tiles_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 00:53:41 by codekiwi          #+#    #+#             */
/*   Updated: 2024/10/02 22:40:37 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <errno.h>

#include "libft.h"
#include "map_bonus.h"
#include "error_bonus.h"
#include "utils_bonus.h"

static char	**read_tiles(int fd, size_t map_size_y, bool skip_empty_line)
{
	char	*line;
	char	**tiles;

	line = get_next_line(fd);
	remove_last_breakline(line);
	if (line == NULL)
	{
		if (errno != 0)
			return (NULL);
		tiles = ft_calloc(map_size_y + 1, sizeof(char *));
		return (tiles);
	}
	if (line[0] == '\0' && skip_empty_line)
	{
		free(line);
		return (read_tiles(fd, map_size_y, true));
	}
	tiles = read_tiles(fd, map_size_y + 1, false);
	if (tiles == NULL)
	{
		free(line);
		return (NULL);
	}
	tiles[map_size_y] = line;
	return (tiles);
}

static bool	get_lines_lengths(t_map *map)
{
	size_t	index;

	index = 0;
	map->lines_count = array_length((void **)map->tiles);
	if (map->lines_count == 0)
		return (error_print(ERR_MAP_EMPTY), false);
	map->lines_lengths = ft_calloc(map->lines_count, sizeof(size_t));
	if (map->lines_lengths == NULL)
		return (false);
	while (map->tiles[index])
	{
		map->lines_lengths[index] = ft_strlen(map->tiles[index]);
		if (map->lines_lengths[index] == 0)
			return (error_print(ERR_EMPTY_LINE), false);
		index++;
	}
	return (true);
}

static bool	map_line_is_empty(char *line)
{
	size_t	i;

	if (line == NULL)
		return (true);
	i = 0;
	while (line[i] != '\0')
	{
		if (!ft_isspace(line[i]))
			return (false);
		i++;
	}
	return (true);
}

static bool	clean_map(char **tiles)
{
	size_t	i;
	size_t	nb_lines;

	if (tiles == NULL)
		return (error_print(ERR_MAP_READ), false);
	nb_lines = array_length((void **)tiles);
	if (nb_lines == 0)
		return (error_print(ERR_MAP_EMPTY), false);
	i = nb_lines;
	while (i > 0 && map_line_is_empty(tiles[i - 1]))
	{
		free(tiles[i - 1]);
		tiles[i - 1] = NULL;
		i--;
	}
	return (true);
}

bool	read_map_tiles(t_map *map, char *filename, t_animation anim[MAP_NB_IDS])
{
	int		fd;

	ft_bzero(map, sizeof(t_map));
	if (!check_extension(filename, MAP_EXTENSION))
		return (error_print(ERR_MAP_EXTENSION), false);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (error_print(ERR_MAP_OPEN), false);
	if (!read_elements(map, fd, anim))
	{
		free_map(map);
		close(fd);
		return (false);
	}
	map->tiles = read_tiles(fd, 0, true);
	close(fd);
	if (
		!clean_map(map->tiles) || !get_lines_lengths(map)
		|| !is_map_valid(map) || !save_map_tiles(map)
	)
	{
		free_map(map);
		return (false);
	}
	return (true);
}
