/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_utility.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 14:11:31 by vkuzmina          #+#    #+#             */
/*   Updated: 2026/08/18 20:25:27 by vkuzmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	better_position(int size, int position, int best)
{
	if (best == -1)
		return (1);
	return (rotation_cost(size, position)
		< rotation_cost(size, best));
}

static int	resolve_b_position(t_node *b, int position)
{
	if (position == -1)
		return (find_position(b, find_largest_index(b)));
	return (position);
}

int	find_b_insert_position(t_node *b, int target)
{
	t_node	*current;
	t_node	*prev;
	int		position;
	int		best_position;
	int		size;

	if (!b)
		return (-1);
	current = b;
	prev = find_last(b);
	best_position = -1;
	size = stack_size(b);
	position = 0;
	while (current)
	{
		if (prev->index > target && target > current->index)
		{
			if (better_position(size, position, best_position))
				best_position = position;
		}
		prev = current;
		current = current->next;
		position++;
	}
	return (resolve_b_position(b, best_position));
}
