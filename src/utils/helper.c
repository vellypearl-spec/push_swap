/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 17:24:22 by vkuzmina          #+#    #+#             */
/*   Updated: 2026/08/16 15:11:49 by vkuzmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_last(t_node *a)
{
	t_node	*last_node;

	if (!a)
		return (NULL);
	last_node = a;
	while (last_node->next)
	{
		last_node = last_node->next;
	}
	return (last_node);
}

t_node	*find_before_last(t_node *a)
{
	t_node	*node_before;

	if (!a || a->next == NULL)
		return (NULL);
	node_before = a;
	while (node_before->next->next)
		node_before = node_before->next;
	return (node_before);
}

int	find_position(t_node *a, int target_index)
{
	t_node	*current;
	int		position;

	if (!a)
		return (-1);
	current = a;
	position = 0;
	while (current)
	{
		if (current->index == target_index)
			return (position);
		current = current->next;
		position++;
	}
	return (-1);
}

void	bring_to_top(t_node **a, int position)
{
	int		size;
	int		rotation;

	size = stack_size(*a);
	rotation = rotation_cost(size, position);
	if (position <= size / 2)
	{
		while (position)
		{
			ra(a);
			--position;
		}
	}
	else
	{
		while (rotation)
		{
			rra(a);
			--rotation;
		}
	}
}
