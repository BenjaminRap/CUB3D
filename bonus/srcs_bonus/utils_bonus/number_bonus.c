/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:10:14 by root              #+#    #+#             */
/*   Updated: 2024/08/27 14:24:15 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

bool	is_number(char *str)
{
	size_t	index;

	if (str == NULL)
		return (false);
	index = 0;
	if (str[index] == '-')
		index++;
	if (str[index] == '\0')
		return (false);
	while (str[index])
	{
		if (str[index] < '0' || str[index] > '9')
			return (false);
		index++;
	}
	return (true);
}
