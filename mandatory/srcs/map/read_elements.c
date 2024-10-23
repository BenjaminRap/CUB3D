/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:29:56 by brappo            #+#    #+#             */
/*   Updated: 2024/08/27 14:32:57 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

static bool	parse_element(t_map *map, char *element, char **identifier)
{
	char	*info;
	ssize_t	identifier_index;

	skip_next_spaces(&element);
	info = ft_strchr(element, ' ');
	if (info == NULL)
		return (error_print(ERR_MISSING_COMPONENT), false);
	*info = '\0';
	info++;
	skip_next_spaces(&info);
	remove_last_spaces(info);
	if (!*info)
		return (error_print(ERR_MISSING_COMPONENT), false);
	identifier_index = find_str_in_array(identifier, element, MAP_NB_IDS);
	if (identifier_index == -1)
		return (error_print(ERR_IDENTIFIER), false);
	map->textures[identifier_index] = ft_strdup(info);
	if (map->textures[identifier_index] == NULL)
		return (false);
	identifier[identifier_index] = "";
	return (true);
}

static void	init_identifier(char **identifier)
{
	identifier[0] = ID_NORTH;
	identifier[1] = ID_SOUTH;
	identifier[2] = ID_WEST;
	identifier[3] = ID_EAST;
	identifier[4] = ID_FLOOR;
	identifier[5] = ID_CEILING;
}

bool	read_elements(t_map *map, int fd)
{
	char			*line;
	unsigned int	elements_read;
	char			*identifier[MAP_NB_IDS];

	elements_read = 0;
	init_identifier(identifier);
	ft_bzero(map->textures, MAP_NB_IDS * sizeof(char *));
	while (elements_read < MAP_NB_IDS)
	{
		line = get_next_line(fd);
		if (line == NULL)
			return (error_print(ERR_MAP_CONTENT), false);
		remove_last_breakline(line);
		if (line[0] != '\0')
		{
			if (!parse_element(map, line, identifier))
			{
				free(line);
				return (false);
			}
			elements_read++;
		}
		free(line);
	}
	return (true);
}
