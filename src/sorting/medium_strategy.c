/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_strategy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 14:28:29 by vkuzmina          #+#    #+#             */
/*   Updated: 2026/08/16 20:33:55 by vkuzmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chunk_size(int size)
{
	int	chunk;

	chunk = 1;
	while (chunk * chunk < size)
		++chunk;
	return (chunk);
}

int	in_chunk(int start, int end, int index)
{
	if (index >= start && index <= end)
		return (1);
	return (0);
}

void	first_phase(t_node **a, t_node **b, int start, int end)
{
	int	to_push;
	int	index;

	to_push = end - start +1;
	while (to_push && *a)
	{
		index = (*a)->index;
		if (in_chunk(start, end, index))
		{
			push_rotate(a, b, start, end);
			--to_push;
		}
		else
			ra(a);
	}
}

void	second_phase(t_node **a, t_node **b)
{
	int	largest;
	int	position;

	while (*b)
	{
		largest = find_largest_index(*b);
		position = find_position(*b, largest);
		bring_to_top(b, position);
		pa(a, b);
	}
}

void	medium_strategy(t_node **a, t_node **b)
{
	int	size;
	int	chunk;
	int	start;
	int	end;

	if (!*a || count_inversions(*a) == 0)
		return ;
	size = stack_size(*a);
	chunk = chunk_size(size);
	start = 0;
	end = chunk - 1;
	while (*a)
	{
		first_phase(a, b, start, end);
		start += chunk;
		end += chunk;
	}
	second_phase(a, b);
}
