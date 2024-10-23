/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 09:20:22 by brappo            #+#    #+#             */
/*   Updated: 2024/06/18 13:06:38 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	remove_last_breakline(char *str)
{
	size_t	length;

	if (str == NULL)
		return ;
	length = ft_strlen(str);
	if (length == 0)
		return ;
	if (str[length - 1] == '\n')
		str[length - 1] = '\0';
}

void	skip_next_spaces(char **str)
{
	if (str == NULL || *str == NULL)
		return ;
	while (**str == ' ')
		*str += 1;
}

void	remove_last_spaces(char *str)
{
	ssize_t	length;

	length = ft_strlen(str);
	if (length == 0)
		return ;
	length--;
	while (length >= 0 && str[length] == ' ')
	{
		str[length] = '\0';
		length--;
	}
}
