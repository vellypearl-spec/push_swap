/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glouis <glouis@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 10:02:30 by glouis            #+#    #+#             */
/*   Updated: 2026/08/18 10:02:30 by glouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int n)
{
	int	bits;
	int	max;

	bits = 0;
	max = n - 1;
	while (max > 0)
	{
		max >>= 1;
		bits++;
	}
	return (bits);
}

static int	handle_small_stack(t_node **a)
{
	int	size;

	size = stack_size(*a);
	if (size <= 3)
	{
		if (size == 2)
			sort_two(a);
		else if (size == 3)
			sort_three(a);
		return (1);
	}
	return (0);
}

void	complex_sort(t_node **a, t_node **b)
{
	int	bits;
	int	bit;
	int	i;
	int	len;

	if (handle_small_stack(a))
		return;
	bits = get_max_bits(stack_size(*a));
	bit = 0;
	while (bit < bits)
	{
		len = stack_size(*a);
		i = 0;
		while (i < len)
		{
			if (!((*a)->index >> bit) & 1)
				pb(a, b);
			else
				ra(a);
			i++;
		}
		while (*b)
			pa(a, b);
		bit++;
	}
}
