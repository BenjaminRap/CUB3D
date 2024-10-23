/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 03:29:13 by brappo            #+#    #+#             */
/*   Updated: 2024/10/02 03:31:13 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_BONUS_H
# define UTILS_BONUS_H

# include <stdlib.h>

typedef struct s_game	t_game;
typedef struct s_list	t_list;

void	error_print(char *err_msg);
void	error_print_string(char *err_msg, char *str);
void	error_print_char(char *err_msg, char c);
void	error_exit(t_game *game, char *err_msg);
size_t	array_length(void **array);
int		sign(float value);
ssize_t	find_str_in_array(char **array, char *str, size_t length);
void	free_array(char **array, size_t length, bool free_container);
char	**create_str_array(size_t nb_row, size_t nb_col, char default_value);
int		min(int a, int b);
int		max_int(int a, int b);
bool	get_random_bool(float probability);
bool	is_number(char *str);
void	remove_last_breakline(char *str);
void	remove_last_spaces(char *str);
void	skip_next_spaces(char **str);
long	get_tick(void);
void	sort_list(t_list *lst, float compare(void *, void *));
float	range(float value, float min, float max);

#endif // !UTILS_BONUS_H