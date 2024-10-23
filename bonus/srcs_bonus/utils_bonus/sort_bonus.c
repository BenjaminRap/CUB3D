/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:56:04 by brappo            #+#    #+#             */
/*   Updated: 2024/10/02 06:23:39 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*max(t_list *lst, float compare(void *, void *))
{
	t_list	*max_element;

	if (lst == NULL)
		return (NULL);
	max_element = lst;
	lst = lst->next;
	while (lst)
	{
		if (compare(lst->content, max_element->content) > 0)
			max_element = lst;
		lst = lst->next;
	}
	return (max_element);
}

static void	swap(void **a, void **b)
{
	void	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	sort_list(t_list *lst, float compare(void *, void *))
{
	t_list	*max_element;

	while (lst->next)
	{
		max_element = max(lst, compare);
		swap(&lst->content, &max_element->content);
		lst = lst->next;
	}
}
