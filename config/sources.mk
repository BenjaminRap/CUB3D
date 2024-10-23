# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sources.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brappo <brappo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/12 10:31:28 by mhotting          #+#    #+#              #
#    Updated: 2024/08/27 16:26:10 by brappo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################################################
#              Variable definitions             #
#################################################

# GENERAL
NAME					=	cub3D
NAME_EXECUTABLE			=	$(addprefix $(EXECUTABLE_DIR), $(NAME))
MANDATORY_DIR			=	mandatory/
HFLAGS					=	-I$(HEADERS_DIR) -I$(LIBFT_HEADERS_DIR) -I$(MLX_DIR)

# DEPS
DEPS_CONFIG				=	$(addprefix $(CONFIG_DIR), sources.mk)

# HEADERS
HEADERS_SUBDIR			=	includes/
HEADERS_DIR				=	$(addprefix $(MANDATORY_DIR), $(HEADERS_SUBDIR))
HEADERS_FILES			=	cub3d.h				\
							mlx_api.h			\
							event_handlers.h	\
							map.h				\
							vector.h
HEADERS					=	$(addprefix $(HEADERS_DIR), $(HEADERS_FILES))

# MAIN
MAIN_DIR				=	main/
MAIN_FILES				=	cub3d.c
MAIN					=	$(addprefix $(MAIN_DIR), $(MAIN_FILES))

# GAME
GAME_DIR				=	game/
GAME_FILES				=	t_game_destroy.c		\
							t_game_init.c			\
							game_loop.c
GAME					=	$(addprefix $(GAME_DIR), $(GAME_FILES))

# MLX_API
MLX_API_DIR				=	mlx_api/
MLX_API_FILES			=	t_image_utils.c			\
							t_mlx_init.c			\
							t_mlx_destroy.c			\
							t_mlx_hook.c			\
							t_mlx_render.c			\
							t_mlx_draw_pixel.c		\
							t_mlx_get_pixel.c		\
							t_mlx_draw_line.c		\
							t_mlx_draw_rectangle.c	\
							t_argb_color_utils.c
MLX_API					=	$(addprefix $(MLX_API_DIR), $(MLX_API_FILES))

# EVENT_HANDLERS
EVENT_HANDLERS_DIR		=	event_handlers/
EVENT_HANDLERS_FILES	=	add_event_handler.c		\
							destroy_handler.c		\
							key_release_handler.c	\
							key_press_handler.c

EVENT_HANDLERS			=	$(addprefix $(EVENT_HANDLERS_DIR), $(EVENT_HANDLERS_FILES))

# BASIC_RENDER
BASIC_RENDER_DIR		=	basic_render/
BASIC_RENDER_FILES		=	draw_walls.c			\
							draw_column.c
BASIC_RENDER			=	$(addprefix $(BASIC_RENDER_DIR), $(BASIC_RENDER_FILES))

# MAP
MAP_DIR					=	map/
MAP_FILES				=	read_map.c				\
							is_in_bounds.c			\
							read_elements.c			\
							is_valid.c				\
							free_map.c
MAP						=	$(addprefix $(MAP_DIR), $(MAP_FILES))

# PLAYER
PLAYER_DIR				=	player/
PLAYER_FILES			=	t_player_init.c	\
							update_player.c
PLAYER					=	$(addprefix $(PLAYER_DIR), $(PLAYER_FILES))

# RAY
RAY_DIR					=	ray/
RAY_FILES				=	raycasting.c			\
							cast_rays.c
RAY						=	$(addprefix $(RAY_DIR), $(RAY_FILES))

# VECTOR
VECTOR_DIR				=	vector/
VECTOR_FILE				=	vector.c
VECTOR					=	$(addprefix $(VECTOR_DIR), $(VECTOR_FILE))

# UTILS
UTILS_DIR				=	utils/
UTILS_FILE				=	math.c					\
							array.c					\
							handle_error.c			\
							number.c				\
							check_extension.c		\
							string.c
UTILS					=	$(addprefix $(UTILS_DIR), $(UTILS_FILE))

# SOURCES GENERAL
SRCS_MAIN_SUBDIR		=	srcs/
SRCS_MAIN_DIR			=	$(addprefix $(MANDATORY_DIR), $(SRCS_MAIN_SUBDIR))
SRCS_FILES				=	$(MAIN) $(MLX_API) $(UTILS) $(GAME) $(VECTOR)	\
							$(EVENT_HANDLERS) $(MAP) $(BASIC_RENDER)		\
							$(PLAYER) $(RAY)
SRCS					=	$(addprefix $(SRCS_MAIN_DIR), $(SRCS_FILES))

# OBJECTS GENERAL
OBJS_MAIN_SUBDIR		=	objs/
OBJS_MAIN_DIR			=	$(addprefix $(MANDATORY_DIR), $(OBJS_MAIN_SUBDIR))
OBJS_FILES				=	$(SRCS_FILES:.c=.o)
OBJS					=	$(addprefix $(OBJS_MAIN_DIR), $(OBJS_FILES))

# DEPENDENCIES
DEPS_MAIN_SUBDIR		=	deps/
DEPS_MAIN_DIR			=	$(addprefix $(MANDATORY_DIR), $(DEPS_MAIN_SUBDIR))
DEPS_FILES				=	$(OBJS_FILES:.o=.d)
DEPS					=	$(addprefix $(DEPS_MAIN_DIR), $(DEPS_FILES))