/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_elements_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:29:56 by brappo            #+#    #+#             */
/*   Updated: 2024/10/02 05:40:24 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "error_bonus.h"
#include "utils_bonus.h"
#include "mlx_api_bonus.h"
#include "map_bonus.h"

static bool	get_texture_size(t_mlx_coords *out, char *size)
{
	char	**values;

	if (out == NULL || size == NULL)
		return (false);
	values = ft_split(size, ",");
	if (array_length((void **)values) != 2
		|| !is_number(values[0]) || !is_number(values[1]))
	{
		ft_free_str_array(&values);
		return (error_print(ERR_BAD_SIZE), false);
	}
	if (ft_strlen(values[0]) >= 5 || ft_strlen(values[1]) >= 5)
	{
		ft_free_str_array(&values);
		return (error_print(ERR_SIZE_TOO_BIG), false);
	}
	out->x = ft_atoi(values[0]);
	out->y = ft_atoi(values[1]);
	ft_free_str_array(&values);
	if (out->x <= 0 || out->y <= 0)
		return (error_print(ERR_NEGATIVE_SIZE), false);
	return (true);
}

static bool	read_animation_wait(float *out, char *wait_time)
{
	int	value;

	if (!is_number(wait_time))
		return (error_print(ERR_BAD_ANIM_TIME), false);
	if (ft_strlen(wait_time) >= 5)
		return (error_print(ERR_ANIM_TIME_TOO_BIG), false);
	value = ft_atoi(wait_time);
	if (value <= 0)
		return (error_print(ERR_ANIM_TIME_NEGATIVE), false);
	*out = (float)value / 1000;
	return (true);
}

static bool	parse_element(t_map *map, char *element, char **identifier, \
	t_animation anim[MAP_NB_IDS])
{
	char	**infos;
	ssize_t	identifier_index;

	infos = ft_split(element, " ");
	if (array_length((void **)infos) != 4)
	{
		ft_free_str_array(&infos);
		return (error_print(ERR_MISSING_COMPONENT), false);
	}
	identifier_index = find_str_in_array(identifier, infos[0], MAP_NB_IDS);
	if (identifier_index == -1)
	{
		error_print_string(ERR_IDENTIFIER, infos[0]);
		ft_free_str_array(&infos);
		return (false);
	}
	if (!get_texture_size(&map->texture_size[identifier_index], infos[2])
		|| !read_animation_wait(&anim[identifier_index].wait, infos[3]))
		return (ft_free_str_array(&infos), false);
	free(infos[2]);
	free(infos[3]);
	map->textures[identifier_index] = infos[1];
	identifier[identifier_index] = "";
	free_array(infos, 1, true);
	return (true);
}

bool	read_elements(t_map *map, int fd, t_animation anim[MAP_NB_IDS])
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
			if (!parse_element(map, line, identifier, anim))
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
