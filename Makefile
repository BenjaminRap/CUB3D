# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/12 10:35:12 by mhotting          #+#    #+#              #
#    Updated: 2024/08/26 10:49:28 by mhotting         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include config/sources_common.mk
include config/sources.mk
include config/sources_bonus.mk

#################################################
#               Rule definitions                #
#################################################

# RULES MANDATORY
all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(HFLAGS) $(OBJS) $(LIBFT_FLAGS) $(MLX_FLAGS) $(EXT_LIB_FLAGS) -o $@

$(OBJS_MAIN_DIR)%.o: $(SRCS_MAIN_DIR)%.c $(DEPS_CONFIG_COMMON) $(DEPS_CONFIG)
	@mkdir -p $(@D)
	@mkdir -p $(DEPS_MAIN_DIR)$(dir $*)
	$(CC) $(CFLAGS) $(HFLAGS) -MP -MMD -MF $(DEPS_MAIN_DIR)$*.d -c $< -o $@ 

# RULES BONUS
bonus: $(NAME_BONUS)

$(NAME_BONUS): $(LIBFT) $(MLX) $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(HFLAGS_BONUS) $(OBJS_BONUS) $(LIBFT_FLAGS) $(MLX_FLAGS) $(EXT_LIB_FLAGS) -o $@

$(OBJS_MAIN_DIR_BONUS)%.o: $(SRCS_MAIN_DIR_BONUS)%.c $(DEPS_CONFIG_COMMON) $(DEPS_CONFIG_BONUS)
	@mkdir -p $(@D)
	@mkdir -p $(DEPS_MAIN_DIR_BONUS)$(dir $*)
	$(CC) $(CFLAGS) $(HFLAGS_BONUS) -MP -MMD -MF $(DEPS_MAIN_DIR_BONUS)$*.d -c $< -o $@ 

$(LIBFT): init_submodule FORCE
	$(MAKE) -sC $(LIBFT_DIR)

$(MLX): init_submodule FORCE
	$(MAKE) -sC $(MLX_DIR) > /dev/null 2>&1

FORCE:

fsanitize: fclean $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(HFLAGS) $(FSFLAGS) $(OBJS) $(LIBFT_FLAGS) $(MLX_FLAGS) $(EXT_LIB_FLAGS) -o $(NAME)

fsanitize-bonus: fclean $(LIBFT) $(MLX) $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(HFLAGS_BONUS) $(FSFLAGS) $(OBJS_BONUS) $(LIBFT_FLAGS) $(MLX_FLAGS) $(EXT_LIB_FLAGS) -o $(NAME_BONUS)

init_submodule:
	@if git submodule status | egrep -q '^[-+]' ; then \
		echo "*Info: Need to initialize git submodules"; \
		git submodule update --init; \
	fi

-include $(DEPS)
-include $(DEPS_BONUS)

clean:
	rm -rf $(OBJS_MAIN_DIR)
	rm -rf $(DEPS_MAIN_DIR)

clean-bonus:
	rm -rf $(OBJS_MAIN_DIR_BONUS)
	rm -rf $(DEPS_MAIN_DIR_BONUS)

clean-libft:
	$(MAKE) -C $(LIBFT_DIR) clean

clean-mlx:
	make -sC $(MLX_DIR) clean > /dev/null 2>&1

fclean: clean
	rm -f $(NAME)

fclean-bonus: clean-bonus
	rm -f $(NAME_BONUS)

fclean-libft:
	$(MAKE) -sC $(LIBFT_DIR) fclean

fclean-mlx: clean-mlx

ffclean: fclean fclean-bonus fclean-libft fclean-mlx

re: fclean all

re-bonus: fclean-bonus bonus

rre: ffclean all

rre-bonus: ffclean bonus

.PHONY: all clean clean-bonus fclean fclean-bonus re re-bonus clean-libft clean-mlx fclean-libft fclean-mlx ffclean rre rre-bonus bonus FORCE fsanitize fsanitize-bonus init_submodule