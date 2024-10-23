/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:21:14 by brappo            #+#    #+#             */
/*   Updated: 2024/08/27 14:36:34 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	check_extension(char *filename, char *extension)
{
	ssize_t	extension_pos;

	if (filename == NULL || extension == NULL)
		return (false);
	extension_pos = ft_strlen(filename);
	while (extension_pos >= 0 && filename[extension_pos] != '.')
		extension_pos--;
	if (extension_pos == -1)
		return (false);
	return (ft_strcmp(filename + extension_pos, extension) == 0);
}
