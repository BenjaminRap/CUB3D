/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 19:09:13 by brappo            #+#    #+#             */
/*   Updated: 2024/08/27 14:16:35 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pathfinding_bonus.h"

/*
	This pathfinding algoritm is called A*, it begin a a given coordinates and 
	calculate for all the neighbors 3 values : distance to start (ds), distance 
	to end (de) and the addition of the two previous (a).The neighbors are then 
	inserted in a stack, sorted by "a", or if they'r equal, by "de".
	It locks the best coordinates ( the one on top) so that it can't be reused,
	and start again with this locked coordinates as the start.
*/

/**
 * @brief add the top node to the locked tiles and removed it from the stack.
 */
static void	lock_tile(t_pathfinding *pathfinding)
{
	t_stack_path	*new_stack;

	new_stack = pathfinding->stack->next;
	pathfinding->stack->next = pathfinding->locked_tiles;
	if (pathfinding->locked_tiles != NULL)
		pathfinding->locked_tiles->previous = pathfinding->stack;
	pathfinding->locked_tiles = pathfinding->stack;
	pathfinding->stack = new_stack;
	if (new_stack != NULL)
	{
		new_stack->previous = NULL;
		if (new_stack->next != NULL)
			new_stack->next->previous = new_stack;
	}
}

/**
 * @brief Find a path from start to end on the given map
 * @return A list of coordinates or NULL if no path is found.
 */
t_list	*find_path(t_mlx_coords *start, t_mlx_coords *end, t_map *map)
{
	t_pathfinding	pathfinding;
	t_list			*path;

	if (start == NULL || end == NULL || map == NULL)
		return (NULL);
	if (!t_pathfinding_init(&pathfinding, start, end, map))
		return (false);
	while (true)
	{
		if (pathfinding.allocation >= MAX_ALLOCATION_FOR_PATH)
			return (t_pathfinding_free(&pathfinding), NULL);
		lock_tile(&pathfinding);
		if (!add_neighboring_tiles(&pathfinding, map))
			return (t_pathfinding_free(&pathfinding), NULL);
		if (pathfinding.stack == NULL)
			return (t_pathfinding_free(&pathfinding), NULL);
		if (pathfinding.stack->position.x == end->x
			&& pathfinding.stack->position.y == end->y)
			break ;
	}
	path = get_parcoured_path(&pathfinding);
	t_pathfinding_free(&pathfinding);
	return (path);
}
