/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glouis <glouis@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 09:13:39 by glouis            #+#    #+#             */
/*   Updated: 2026/08/17 09:13:39 by glouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_chunk_size(int n)
{
	int	size;

	size = 1;
	while (size * size < n)
		size++;
	return (size);
}

static void	fill_chunk(t_node **a, t_node **b, int min, int max)
{
	int	len;
	int	i;

	len = size(*a);
	i = 0;
	while (i < len)
	{
		if ((*a)->index >= min && (*a)->index < max)
			pb(a, b);
		else
			ra(a);
		i++;
	}
}

static void	insert_chunk_descending(t_node **a, t_node **b)
{
	t_node	*target;
	int		best;
	int		len;
	int		i;

	while (*b)
	{
		target = *b;
		best = target->value;
		len = size(*b);
		i = 0;
		while (i < len)
		{
			if ((*b)->value > best)
				best = (*b)->value;
			rb(b);
			i++;
		}
		while ((*b)->value != best)
			rb(b);
		pa(a, b);
	}
}

void	medium_sort(t_node **a, t_node **b)
{
	int	n;
	int	chunk_size;
	int	num_chunks;
	int	chunk;
	int	min;
	int	max;

	n = size(*a);
	chunk_size = get_chunk_size(n);
	num_chunks = (n + chunk_size - 1) / chunk_size;
	chunk = num_chunks - 1;
	while (chunk >= 0)
	{
		min = chunk * chunk_size;
		max = min + chunk_size;
		if (max > n)
			max = n;
		fill_chunk(a, b, min, max);
		insert_chunk_descending(a, b);
		chunk--;
	}
}
