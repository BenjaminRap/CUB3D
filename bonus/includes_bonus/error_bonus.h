/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 03:24:07 by brappo            #+#    #+#             */
/*   Updated: 2024/10/02 09:28:39 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_BONUS_H
# define ERROR_BONUS_H

# define ERR_BASIC				"Error\n"
# define ERR_LITERALS			"Error\n%s\n"
# define ERR_LITERALS_STR		"Error\n%s %s\n"
# define ERR_LITERALS_CHAR		"Error\n%s '%c'\n"

# define ERR_ARG				"Bad argument given to the function"
# define ERR_PROG_ARGS			"Bad arguments, no argument expected"
# define ERR_GAME_INIT			"Impossible to intialize the t_game structure"
# define ERR_MLX_INIT			"Impossible to intialize the t_mlx structure"
# define ERR_GAME_LOOP			"Game loop failed"
# define ERR_HOOKS				"Impossible to add event handling"
# define ERR_RENDER				"Rendering error"
# define ERR_CAST_RAYS			"Ran in a wall"

# define ERR_FPS				"Error calculating fps"
# define INVALID_DOOR			"Door should be between two walls."
# define ERR_WALLS				"Map not surrounded by walls"
# define ERR_ELEM				"Map elements not valid"
# define ERR_IDENTIFIER			"Map unknown identifier"
# define ERR_EMPTY_LINE			"Empty line in the map content"
# define ERR_MAP_EXTENSION		"Bad map extension, expected '.cub'"
# define ERR_MULTIPLE_PLAYERS	"Multiple players on the map"
# define ERR_MISSING_PLAYER		"Missing player"
# define ERR_PLAYER_CREATION	"Impossible to create the player"
# define ERR_MAP_EMPTY			"Missing map content"
# define ERR_PLAYER_QUIT_MAP	"Player out of bounds of the map"
# define ERR_MAP_OPEN			"Impossible to open the given map file"
# define ERR_MAP_CONTENT		"Reading failed, check the map content"
# define ERR_MISSING_TEXTURES	"Missing texture"
# define ERR_MAP_READ			"Map: read failed"
# define ERR_BAD_SIZE			"Wrong or missing texture size"
# define ERR_SIZE_TOO_BIG		"Size too big, max 4 characters"
# define ERR_NEGATIVE_SIZE		"Invalid negative size"
# define ERR_RADAR_CREATION		"Radar creation failed"
# define ERR_MAP_DRAW_CREATION	"Map drawing cannot be created"
# define ERR_MAP_DRAW_SIZE		"Map drawing cannot be initialized: map too big"
# define ERR_WEAPONS_CREATION	"Weapons creation failed"
# define ERR_WEAPONS_RESIZE		"Weapon resizing failed"
# define ERR_P_WEAPONS_CREATION	"Player weapons creation failed"
# define ERR_ENTITY_CREATION	"Impossible to create the entity list"
# define ERR_TOO_MUCH_ENTITIES	"The map contains too much entities"

# define ERR_UIS_CREATION		"UIs could not be created"
# define ERR_UIS_IDS_CREATION	"UIs identifiers could not be set"
# define ERR_UIS_TXTR_PATH		"The UIs texture file could not be opened"
# define ERR_UIS_READ			"Impossible to read the texture file for UIs"
# define ERR_UIS_READ_ELEMENT	"Impossible to read one of the UIs textures"
# define ERR_UIS_IDENTIFIER		"Invalid or duplicated identifier for UIs"
# define ERR_UIS_IMG_INIT		"Impossible to initate image from file"
# define ERR_UI_CREATION		"UI creation failed"

# define ERR_INIT_TEXTURES		"Can't open texture"
# define ERR_TEXTURE_EXTENSION	"Bad texture extension, expected '.xpm'"
# define ERR_MISSING_COMPONENT	"Missing element component"
# define ERR_TEXTURE_SIZE		"Wrong texture size"
# define ERR_MAP_LOAD			"Impossible to load the map"
# define ERR_MAP_UNLOAD			"Impossible to unload the map"

# define ERR_RECTANGLE			"You tried to draw an invalid rectangle"

# define ERR_BAD_ANIM_TIME		"The animation wait time is not a number"	
# define ERR_ANIM_TIME_TOO_BIG	"The animation wait time is too big"
# define ERR_ANIM_TIME_NEGATIVE	"The animation wait time is negative"

# define ERR_DRAW_WALL			"The wall drawing failed"
# define ERR_UPDATE_ENTITIES	"The entity updating process failed"
# define ERR_UPDATE_ANIMATIONS	"The animation updating process failed"

typedef struct s_game	t_game;

void	error_print(char *err_msg);
void	error_print_string(char *err_msg, char *str);
void	error_print_char(char *err_msg, char c);
void	error_exit(t_game *game, char *err_msg);

#endif // !ERROR_BONUS_H