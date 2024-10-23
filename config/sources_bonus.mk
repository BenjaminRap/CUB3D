# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sources_bonus.mk                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brappo <brappo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/19 11:26:46 by mhotting          #+#    #+#              #
#    Updated: 2024/09/13 03:48:35 by brappo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################################################
#              Variable definitions             #
#################################################

NAME_BONUS					=	cub3D_bonus
NAME_EXECUTABLE_BONUS		=	$(addprefix $(EXECUTABLE_DIR), $(NAME_BONUS))
BONUS_DIR					=	bonus/
HFLAGS_BONUS				=	-I$(HEADERS_DIR_BONUS) -I$(LIBFT_HEADERS_DIR) -I$(MLX_DIR)

# DEPS
DEPS_CONFIG_BONUS			=	$(addprefix $(CONFIG_DIR), sources_bonus.mk)

# HEADERS
HEADERS_SUBDIR_BONUS		=	includes_bonus/
HEADERS_DIR_BONUS			=	$(addprefix $(BONUS_DIR), $(HEADERS_SUBDIR_BONUS))
HEADERS_FILES_BONUS			=	cub3d_bonus.h 					\
								mlx_api_bonus.h					\
								event_handlers_bonus.h 			\
								map_bonus.h						\
								vector_bonus.h					\
								lightmap_bonus.h
HEADERS_BONUS				=	$(addprefix $(HEADERS_DIR_BONUS), $(HEADERS_FILES_BONUS))

# MAIN
MAIN_DIR_BONUS				=	main_bonus/
MAIN_FILES_BONUS			=	cub3d_bonus.c
MAIN_BONUS					=	$(addprefix $(MAIN_DIR_BONUS), $(MAIN_FILES_BONUS))

# GAME
GAME_DIR_BONUS				=	game_bonus/
GAME_FILES_BONUS			=	t_game_destroy_bonus.c			\
								t_game_init_bonus.c				\
								game_loop_bonus.c				\
								game_pause_bonus.c				\
								game_level_selection1_bonus.c	\
								game_level_selection2_bonus.c	\
								game_level_selection_utils_bonus.c	\
								game_home_bonus.c
GAME_BONUS					=	$(addprefix $(GAME_DIR_BONUS), $(GAME_FILES_BONUS))

# MLX_API
MLX_API_DIR_BONUS			=	mlx_api_bonus/
MLX_API_FILES_BONUS			=	t_image_utils_bonus.c			\
								t_image_resize_bonus.c			\
								t_image_color_bonus.c			\
								t_mlx_mouse_utils_bonus.c		\
								t_mlx_init_bonus.c				\
								t_mlx_destroy_bonus.c			\
								t_mlx_hook_bonus.c				\
								t_mlx_render_bonus.c			\
								t_mlx_draw_pixel_bonus.c		\
								t_mlx_get_pixel_bonus.c			\
								t_mlx_draw_line_bonus.c			\
								t_mlx_draw_rectangle_bonus.c	\
								t_mlx_draw_circle_bonus.c		\
								t_mlx_draw_disk_bonus.c			\
								t_mlx_draw_disk_circle_utils.c	\
								t_argb_color_utils_bonus.c		\
								t_mlx_sync_images.c
MLX_API_BONUS				=	$(addprefix $(MLX_API_DIR_BONUS), $(MLX_API_FILES_BONUS))

# EVENT_HANDLERS
EVENT_HANDLERS_DIR_BONUS	=	event_handlers_bonus/
EVENT_HANDLERS_FILES_BONUS	=	add_event_handler_bonus.c		\
								destroy_handler_bonus.c			\
								key_release_handler_bonus.c		\
								key_press_handler_bonus.c		\
								mouse_press_handler_bonus.c		\
								mouse_release_handler_bonus.c	\
								mouse_move_handler_bonus.c
EVENT_HANDLERS_BONUS		=	$(addprefix $(EVENT_HANDLERS_DIR_BONUS), $(EVENT_HANDLERS_FILES_BONUS))

# RENDER
RENDER_DIR_BONUS			=	render_bonus/
RENDER_FILES_BONUS			=	draw_walls_bonus.c				\
								draw_walls_part_bonus.c			\
								draw_column_bonus.c				\
								draw_ceiling_ground_bonus.c		\
								draw_sprite_bonus.c				\
								sprite_screen_position_bonus.c	\
								offset_bonus.c					\
								draw_sky_bonus.c
RENDER_BONUS				=	$(addprefix $(RENDER_DIR_BONUS), $(RENDER_FILES_BONUS))

# MAP
MAP_DIR_BONUS				=	map_bonus/
MAP_FILES_BONUS				=	read_map_tiles_bonus.c			\
								read_maps_bonus.c				\
								save_tiles_bonus.c				\
								is_in_bounds_bonus.c			\
								read_elements_bonus.c			\
								is_valid_bonus.c				\
								free_map_bonus.c				\
								get_elem_bonus.c				\
								init_identifier1_bonus.c		\
								init_identifier2_bonus.c		\
								update_bonus.c					\
								draw_bonus.c					\
								draw_entities_bonus.c			\
								init_draw_bonus.c
MAP_BONUS					=	$(addprefix $(MAP_DIR_BONUS), $(MAP_FILES_BONUS))

# DOOR
DOOR_DIR_BONUS				=	door_bonus/
DOOR_FILES_BONUS			=	find_doors_bonus.c				\
								open_door_bonus.c				\
								update_door_bonus.c				\
								init_doors_bonus.c				\
								restore_doors_bonus.c
DOOR_BONUS					=	$(addprefix $(DOOR_DIR_BONUS), $(DOOR_FILES_BONUS))

# PLAYER
PLAYER_DIR_BONUS			=	player_bonus/
PLAYER_FILES_BONUS			=	t_player_init_bonus.c			\
								update_player_bonus.c			\
								move_player_bonus.c				\
								update_player_weapon_bonus.c	\
								player_get_damage_bonus.c		\
								weapons_utils_bonus.c			\
								draw_bonus.c					\
								player_vertical_move_bonus.c
PLAYER_BONUS				=	$(addprefix $(PLAYER_DIR_BONUS), $(PLAYER_FILES_BONUS))

# RAY
RAY_DIR_BONUS				=	ray_bonus/
RAY_FILES_BONUS				=	raycasting_bonus.c				\
								cast_rays_bonus.c				\
								is_door_bonus.c
RAY_BONUS					=	$(addprefix $(RAY_DIR_BONUS), $(RAY_FILES_BONUS))

# VECTOR
VECTOR_DIR_BONUS			=	vector_bonus/
VECTOR_FILES_BONUS			=	vector_utils1_bonus.c			\
								vector_utils2_bonus.c
VECTOR_BONUS				=	$(addprefix $(VECTOR_DIR_BONUS), $(VECTOR_FILES_BONUS))

# SPRITES
SPRITES_DIR_BONUS			=	sprites_bonus/
SPRITES_FILES_BONUS			=	sprite_distance_bonus.c			\
								sprite_init_bonus.c
SPRITES_BONUS				=	$(addprefix $(SPRITES_DIR_BONUS), $(SPRITES_FILES_BONUS))

# UI
UI_DIR_BONUS				=	ui_bonus/
UI_FILES_BONUS				=	ui_utils_bonus.c				\
								init_bonus.c					\
								read_elements_bonus.c			\
								destroy_bonus.c					\
								init_ui_pause_bonus.c			\
								init_ui_gameover_bonus.c		\
								init_ui_win_bonus.c				\
								init_ui_home_bonus.c			\
								init_ui_lvl1_bonus.c			\
								init_ui_lvl2_bonus.c			\
								label_utils_bonus.c				\
								button_utils_bonus.c
UI_BONUS					=	$(addprefix $(UI_DIR_BONUS), $(UI_FILES_BONUS))

# HUD
HUD_DIR_BONUS				=	hud_bonus/
HUD_FILES_BONUS				=	init_bonus.c					\
								draw_bonus.c
HUD_BONUS					=	$(addprefix $(HUD_DIR_BONUS), $(HUD_FILES_BONUS))

# PATHFINDING
PATHFINDING_DIR_BONUS		=	pathfinding_bonus/
PATHFINDING_FILES_BONUS		=	add_path_node_bonus.c			\
								get_parcoured_path_bonus.c		\
								insert_path_node_bonus.c		\
								pathfinding_bonus.c				\
								t_pathfinding_utils_bonus.c		\
								add_neighboring_tiles_bonus.c
PATHFINDING_BONUS			=	$(addprefix $(PATHFINDING_DIR_BONUS), $(PATHFINDING_FILES_BONUS))

# ENTITIES
ENTITIES_DIR_BONUS			=	entities_bonus/
ENTITIES_FILES_BONUS		=	update_entities_bonus.c			\
								init_entities_bonus.c			\
								t_entity_destroy_bonus.c		\
								update_entities_path_bonus.c	\
								move_entity_bonus.c				\
								damage_entity_bonus.c			\
								entity_shoot_bullet_bonus.c		\
								is_sprite_of_entity_bonus.c		\
								update_entities_position_bonus.c
ENTITIES_BONUS				=	$(addprefix $(ENTITIES_DIR_BONUS), $(ENTITIES_FILES_BONUS))

# ENTITY_TYPE
ENTITY_TYPE_DIR_BONUS		=	entity_type_bonus/
ENTITY_TYPE_FILES_BONUS		=	demon_bonus.c					\
								imp_bonus.c						\
								caco_bonus.c					\
								boh_bonus.c						\
								lost_soul_bonus.c				\
								pain_elem_bonus.c				\
								cyber_bonus.c					\
								revenant_bonus.c				\
								mancubus_bonus.c				\
								sergeant_bonus.c				\
								commando_bonus.c				\
								init_entity_type_bonus.c		\
								entities_actions_bonus.c		\
								entities_attack_bonus.c
ENTITY_TYPE_BONUS			=	$(addprefix $(ENTITY_TYPE_DIR_BONUS), $(ENTITY_TYPE_FILES_BONUS))

# RADAR
RADAR_DIR_BONUS				=	radar_bonus/
RADAR_FILES_BONUS			=	utils_bonus.c					\
								draw_bonus.c					\
								rotate_bonus.c					\
								update_tiles_bonus.c
RADAR_BONUS					=	$(addprefix $(RADAR_DIR_BONUS), $(RADAR_FILES_BONUS))

# ANIMATION
ANIMATION_DIR_BONUS			=	animation_bonus/
ANIMATION_FILES_BONUS		=	create_animation_bonus.c		\
								destroy_animation_bonus.c		\
								update_animations_bonus.c		\
								set_animation_bonus.c
ANIMATION_BONUS				=	$(addprefix $(ANIMATION_DIR_BONUS), $(ANIMATION_FILES_BONUS))

# BULLETS
BULLETS_DIR_BONUS			=	bullets_bonus/
BULLETS_FILES_BONUS			=	shoot_bullet_bonus.c			\
								update_bullet_bonus.c			\
								move_bullet_bonus.c				\
								projectile_use_bonus.c			\
								caco_projectile_bonus.c			\
								imp_projectile_bonus.c			\
								boh_projectile_bonus.c			\
								mancubus_projectile_bonus.c		\
								rocket_bonus.c					\
								revenant_projectile_bonus.c		\
								player_basic_projectile_bonus.c
BULLETS_BONUS				=	$(addprefix $(BULLETS_DIR_BONUS), $(BULLETS_FILES_BONUS))

# WEAPONS
WEAPONS_DIR_BONUS			=	weapons_bonus/
WEAPONS_FILES_BONUS			=	init_bonus.c					\
								reload_bonus.c					\
								weapon_init1_bonus.c			\
								weapon_init2_bonus.c			\
								init_resize_bonus.c				\
								handle_positions_bonus.c		\
								update_bonus.c					\
								use_bonus.c						\
								callbacks_bonus.c				\
								update_cooldown_bonus.c
WEAPONS_BONUS				=	$(addprefix $(WEAPONS_DIR_BONUS), $(WEAPONS_FILES_BONUS))

# LIGHTS
LIGHTS_DIR_BONUS			=	lights_bonus/
LIGHTS_FILES_BONUS			=	get_lights_position_bonus.c		\
								get_luminosity_bonus.c			\
								init_lights_bonus.c				\
								set_lights_values_bonus.c
LIGHTS_BONUS				=	$(addprefix $(LIGHTS_DIR_BONUS), $(LIGHTS_FILES_BONUS))

# UTILS
UTILS_DIR_BONUS				=	utils_bonus/
UTILS_FILES_BONUS			=	math_bonus.c					\
								array_bonus.c					\
								handle_error_bonus.c			\
								number_bonus.c					\
								check_extension_bonus.c			\
								string_bonus.c					\
								get_tick_bonus.c				\
								sort_bonus.c
UTILS_BONUS					=	$(addprefix $(UTILS_DIR_BONUS), $(UTILS_FILES_BONUS))

# SOURCES GENERAL
SRCS_MAIN_SUBDIR_BONUS		=	srcs_bonus/
SRCS_MAIN_DIR_BONUS			=	$(addprefix $(BONUS_DIR), $(SRCS_MAIN_SUBDIR_BONUS))
SRCS_FILES_BONUS			=	$(MAIN_BONUS) $(MLX_API_BONUS) $(UTILS_BONUS) 			\
								$(GAME_BONUS) $(VECTOR_BONUS) $(EVENT_HANDLERS_BONUS) 	\
								$(MAP_BONUS) $(RENDER_BONUS) $(PLAYER_BONUS) 			\
								$(RAY_BONUS) $(DOOR_BONUS) $(SPRITES_BONUS)				\
								$(PATHFINDING_BONUS) $(ANIMATION_BONUS)					\
								$(ENTITIES_BONUS) $(UI_BONUS) $(WEAPONS_BONUS)			\
								$(BULLETS_BONUS) $(ENTITY_TYPE_BONUS) $(RADAR_BONUS)	\
								$(HUD_BONUS) $(LIGHTS_BONUS)
SRCS_BONUS					=	$(addprefix $(SRCS_MAIN_DIR_BONUS), $(SRCS_FILES_BONUS))

# OBJECTS GENERAL
OBJS_MAIN_SUBDIR_BONUS		=	objs_bonus/
OBJS_MAIN_DIR_BONUS			=	$(addprefix $(BONUS_DIR), $(OBJS_MAIN_SUBDIR_BONUS))
OBJS_FILES_BONUS			=	$(SRCS_FILES_BONUS:.c=.o)
OBJS_BONUS					=	$(addprefix $(OBJS_MAIN_DIR_BONUS), $(OBJS_FILES_BONUS))

# DEPENDENCIES
DEPS_MAIN_SUBDIR_BONUS		=	deps_bonus/
DEPS_MAIN_DIR_BONUS			=	$(addprefix $(BONUS_DIR), $(DEPS_MAIN_SUBDIR_BONUS))
DEPS_FILES_BONUS			=	$(OBJS_FILES_BONUS:.o=.d)
DEPS_BONUS					=	$(addprefix $(DEPS_MAIN_DIR_BONUS), $(DEPS_FILES_BONUS))