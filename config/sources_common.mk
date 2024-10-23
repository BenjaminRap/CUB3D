# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sources_common.mk                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/19 12:14:29 by mhotting          #+#    #+#              #
#    Updated: 2024/09/02 14:17:57 by mhotting         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################################################
#              Variable definitions             #
#################################################

EXECUTABLE_DIR			=	./
CC						=	cc
ifndef NOFLAGS
	CFLAGS				=	-Wall -Werror -Wextra -O3 -g
endif
FSFLAGS					=	-fsanitize=address
EXT_LIB_FLAGS			=	-lm

# DEPS
CONFIG_DIR				=	config/
DEPS_CONFIG_COMMON		=	Makefile	\
							$(addprefix $(CONFIG_DIR), sources_common.mk)

# LIBFT
LIBFT_DIR				=	libft/
LIBFT_FILE				=	libft.a
LIBFT					=	$(addprefix $(LIBFT_DIR), $(LIBFT_FILE))
LIBFT_HEADERS_SUBDIR	=	includes/
LIBFT_HEADERS_DIR		=	$(addprefix $(LIBFT_DIR), $(LIBFT_HEADERS_SUBDIR))
LIBFT_HEADERS_FILE		=	libft.h
LIBFT_HEADERS			=	$(addprefix $(LIBFT_HEADERS_DIR), $(LIBFT_HEADERS_FILE))
LIBFT_FLAGS				=	-L$(LIBFT_DIR) -lft 

# MLX
MLX_DIR					=	mlx/
MLX_FILE				=	libmlx_Linux.a
MLX						=	$(addprefix $(MLX_DIR), $(MLX_FILE))
MLX_HEADERS_FILE		=	mlx.h
MLX_HEADERS				=	$(addprefix $(MLX_DIR), $(MLX_HEADER_FILE))
MLX_FLAGS				=	-L$(MLX_DIR) -lmlx_Linux -lXext -lX11