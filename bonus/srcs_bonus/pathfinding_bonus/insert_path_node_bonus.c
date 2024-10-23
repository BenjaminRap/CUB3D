/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_path_node_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 10:31:13 by brappo            #+#    #+#             */
/*   Updated: 2024/08/27 14:16:21 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pathfinding_bonus.h"

/**
 * @brief Compare a and by by "a" (see pathfinding_bonus.c), or, if they'r
 * @brief equals, "de".
 */
static int	compare_path_node(t_stack_path *a, t_stack_path *b)
{
	int	total_cost_diff;

	total_cost_diff = a->total_cost - b->total_cost;
	if (total_cost_diff == 0)
		return (a->end_distance - b->end_distance);
	return (total_cost_diff);
}

/**
 * @brief Insert the node new_node into stack, sorted.
 */
void	insert_path_node(t_stack_path **stack, t_stack_path *new_node)
{
	t_stack_path	*current;
	t_stack_path	*previous;

	if (*stack == NULL || compare_path_node(new_node, *stack) < 0)
	{
		new_node->next = *stack;
		if (*stack != NULL)
			(*stack)->previous = new_node;
		*stack = new_node;
		return ;
	}
	previous = *stack;
	current = previous->next;
	while (current)
	{
		if (compare_path_node(new_node, current) < 0)
			break ;
		previous = current;
		current = current->next;
	}
	if (previous->next != NULL)
		previous->next->previous = new_node;
	new_node->next = previous->next;
	previous->next = new_node;
	new_node->previous = previous;
}
