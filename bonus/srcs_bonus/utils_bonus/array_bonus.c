/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:43:57 by brappo            #+#    #+#             */
/*   Updated: 2024/08/27 15:35:09 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	array_length(void **array)
{
	size_t	index;

	if (array == NULL)
		return (0);
	index = 0;
	while (array[index] != NULL)
		index++;
	return (index);
}

void	free_array(char **array, size_t length, bool free_container)
{
	size_t	index;

	index = 0;
	if (array == NULL)
		return ;
	while (index < length)
	{
		if (array[index] != NULL)
		{
			free(array[index]);
			array[index] = NULL;
		}
		index++;
	}
	if (free_container)
		free(array);
}

ssize_t	find_str_in_array(char **array, char *str, size_t length)
{
	size_t	index;

	index = 0;
	while (index < length)
	{
		if (ft_strcmp(array[index], str) == 0)
			return (index);
		index++;
	}
	return (-1);
}

char	**create_str_array(size_t nb_row, size_t nb_col, char default_value)
{
	char	**array;
	size_t	i;

	if (nb_row == 0 || nb_col == 0)
		return (NULL);
	array = (char **) ft_calloc(nb_row + 1, sizeof(char *));
	if (array == NULL)
		return (NULL);
	i = 0;
	while (i < nb_row)
	{
		array[i] = ft_calloc(nb_col, sizeof(char));
		ft_memset(array[i], default_value, nb_col);
		if (array[i] == NULL)
		{
			ft_free_str_array(&array);
			return (NULL);
		}
		i++;
	}
	return (array);
}
