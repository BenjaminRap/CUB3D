/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:43:57 by brappo            #+#    #+#             */
/*   Updated: 2024/08/27 14:36:23 by brappo           ###   ########.fr       */
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
