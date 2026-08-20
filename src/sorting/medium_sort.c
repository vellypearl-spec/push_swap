/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 09:13:39 by glouis            #+#    #+#             */
/*   Updated: 2026/08/20 10:04:58 by vkuzmina         ###   ########.fr       */
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

	len = stack_size(*a);
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
	int	best;
	int	position;

	while (*b)
	{
		best = find_largest_index(*b);
		position = find_position(*b, best);
		bring_to_top_b(b, position);
		pa(a, b);
	}
}

static void	run_chunks(t_node **a, t_node **b, int chunk_size, int n)
{
	int	min;
	int	max;
	int	chunk;
	int	num_chunks;

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

void	medium_sort(t_node **a, t_node **b)
{
	int	n;
	int	chunk_size;

	if (!*a || count_inversions(*a) == 0)
		return ;
	n = stack_size(*a);
	chunk_size = get_chunk_size(n);
	run_chunks(a, b, chunk_size, n);
}
