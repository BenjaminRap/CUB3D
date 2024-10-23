/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_parcoured_path_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 10:58:32 by brappo            #+#    #+#             */
/*   Updated: 2024/08/27 14:16:14 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pathfinding_bonus.h"
#include "libft.h"

static bool	add_position_node(t_list **path, t_mlx_coords *position)
{
	t_mlx_coords	*new_position;
	t_list			*new_node;

	new_position = malloc(sizeof(t_mlx_coords));
	if (new_position == NULL)
		return (false);
	new_position->x = position->x;
	new_position->y = position->y;
	new_node = ft_lstnew(new_position);
	if (new_node == NULL)
	{
		free(new_position);
		return (false);
	}
	ft_lstadd_front(path, new_node);
	return (true);
}

/**
 * @brief Each node has a previous variable, when the algorithm has found the 
 * @brief end coordinates, we can get all the previous until reaching the start 
 * @brief coordinates, it gives us the best path.
 * @return Returns the final, shortest path.
 */
t_list	*get_parcoured_path(t_pathfinding *pathfinding)
{
	t_stack_path	*current;
	t_list			*path;

	current = pathfinding->stack;
	path = NULL;
	while (current->position.x != pathfinding->start->x
		|| current->position.y != pathfinding->start->y)
	{
		if (!add_position_node(&path, &current->position))
		{
			ft_lstclear(&path, free);
			return (NULL);
		}
		current = current->previous_tile;
	}
	return (path);
}
