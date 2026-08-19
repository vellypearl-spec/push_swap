/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_calculation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 20:23:35 by vkuzmina          #+#    #+#             */
/*   Updated: 2026/08/19 14:40:14 by vkuzmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_best_candidate(t_node *a, int min, int max)
{
	int		current_cost;
	int		best_cost;
	int		index;
	int		best_index;

	best_cost = 0;
	best_index = -1;
	index = min;
	while (index < max)
	{
		current_cost = candidate_cost(a, index);
		if (current_cost >= 0)
		{
			if (best_index == -1 || current_cost < best_cost)
			{
				best_cost = current_cost;
				best_index = index;
			}
		}
		index++;
	}
	return (best_index);
}

int	candidate_gain(int baseline, int cost, int rank_gap)
{
	return (baseline - cost - rank_gap);
}

static int	find_best_gain_index(t_node *a, int min, int max)
{
	int	baseline;
	int	best_gain;
	int	cost;
	int	index;
	int	best_index;

	baseline = candidate_cost(a, min);
	best_gain = 0;
	best_index = min;
	index = min + 1;
	while (index < max)
	{
		cost = candidate_cost(a, index);
		if (cost >= 0)
		{
			cost = candidate_gain(baseline, cost, index - min);
			if (cost > best_gain)
			{
				best_gain = cost;
				best_index = index;
			}
		}
		index++;
	}
	return (best_index);
}

int	calculate_window(t_node *a, int min)
{
	int	max;
	int	best_index;

	if (!a)
		return (0);
	max = find_largest_index(a) + 1;
	best_index = find_best_gain_index(a, min, max);
	return (best_index - min + 1);
}
