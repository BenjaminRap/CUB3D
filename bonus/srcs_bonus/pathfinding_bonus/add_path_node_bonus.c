/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_path_node_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 10:30:00 by brappo            #+#    #+#             */
/*   Updated: 2024/10/02 05:49:37 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pathfinding_bonus.h"
#include "utils_bonus.h"

static size_t	get_end_distance(t_mlx_coords *position, t_mlx_coords *end)
{
	int		x_diff;
	int		y_diff;

	x_diff = abs(end->x - position->x);
	y_diff = abs(end->y - position->y);
	return (min(x_diff, y_diff) * 14 + abs(x_diff - y_diff) * 10);
}

static size_t	get_start_distance(t_stack_path *previous, size_t distance)
{
	if (previous == NULL)
		return (0);
	return (previous->start_distance + distance);
}

static bool	update_existing_node(t_stack_path *new_node, size_t total_cost,
	t_stack_path **stack)
{
	if (new_node->total_cost < total_cost)
		return (true);
	if (new_node == *stack)
		*stack = new_node->next;
	if (new_node->previous != NULL)
		new_node->previous->next = new_node->next;
	if (new_node->next != NULL)
		new_node->next->previous = new_node->previous;
	return (false);
}

static t_stack_path	*add_new_node(t_mlx_coords *position)
{
	t_stack_path	*new_node;

	new_node = malloc(sizeof(t_stack_path));
	if (new_node == NULL)
		return (NULL);
	new_node->position.x = position->x;
	new_node->position.y = position->y;
	return (new_node);
}

/**
 * @brief Add the node to the stack. If a node with the same positions exists, 
 * @brief we replace it only if the new node has a better score.
 */
bool	add_path_node(t_mlx_coords *position, t_pathfinding *pathfinding,
	t_stack_path *previous, size_t distance)
{
	t_stack_path	*new_node;
	size_t			start_distance;
	size_t			end_distance;

	if (position == NULL || pathfinding == NULL)
		return (false);
	pathfinding->allocation++;
	end_distance = get_end_distance(position, pathfinding->end);
	start_distance = get_start_distance(previous, distance);
	new_node = search_in_stack(pathfinding->stack, position);
	if (new_node == NULL)
		new_node = add_new_node(position);
	else if (update_existing_node(new_node, start_distance + end_distance,
			&pathfinding->stack))
		return (true);
	if (new_node == NULL)
		return (false);
	new_node->previous_tile = previous;
	new_node->next = NULL;
	new_node->start_distance = start_distance;
	new_node->end_distance = end_distance;
	new_node->total_cost = start_distance + end_distance;
	insert_path_node(&pathfinding->stack, new_node);
	return (true);
}
