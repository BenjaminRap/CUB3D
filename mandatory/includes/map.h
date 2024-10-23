/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 23:55:44 by codekiwi          #+#    #+#             */
/*   Updated: 2024/06/18 12:18:30 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <stdlib.h>

# define ID_WALL			'1'
# define ID_TILE			'0'
# define ID_SPACE			' '

# define ID_NORTH			"NO"
# define ID_SOUTH			"SO"
# define ID_WEST			"WE"
# define ID_EAST			"EA"
# define ID_FLOOR			"F"
# define ID_CEILING			"C"

# define MAP_EXTENSION		".cub"
# define MAP_ALLOWED_CHARS	" 01NSEW"
# define MAP_NB_IDS			6
# define MAP_NB_TEXTURES	4

typedef struct s_game	t_game;
typedef struct s_map	t_map;
typedef struct s_vector	t_vector;

struct s_map
{
	char	**tiles;
	size_t	*lines_lengths;
	size_t	lines_count;
	char	*textures[MAP_NB_IDS];
};

// Map functions
bool		read_map(t_map *map, char *filename);
bool		is_map_valid(t_map *map);
bool		read_elements(t_map *map, int fd);
bool		is_in_bounds(t_vector *position, t_map *map);
bool		is_wall(t_vector *position, t_map *map);
bool		check_extension(char *filename, char *extension);
void		free_map(t_map *map);

#endif
