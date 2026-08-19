/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_strategy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 17:40:03 by vkuzmina          #+#    #+#             */
/*   Updated: 2026/08/19 15:18:06 by vkuzmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	next_min(t_node *a, int min)
{
	while (a && find_position(a, min) < 0)
		min++;
	return (min);
}

static void	move_target(t_node **a, t_node **b, int target)
{
	int	a_position;
	int	b_position;
	int	a_cost;
	int	ride_cost;

	a_position = find_position(*a, target);
	if (!*b)
		bring_to_top(a, a_position);
	else
	{
		b_position = find_b_insert_position(*b, target);
		a_cost = rotation_cost(stack_size(*a), a_position);
		ride_cost = hitchike(*a, *b, a_position, b_position);
		if (ride_cost <= a_cost)
			execute_hitchike(a, b, a_position, b_position);
		else
			bring_to_top(a, a_position);
	}
	pb(a, b);
}

void	distribution(t_node **a, t_node **b)
{
	int	min;
	int	max;
	int	window;
	int	target;

	min = 0;
	while (*a)
	{
		min = next_min(*a, min);
		window = calculate_window(*a, min);
		max = min + window;
		target = find_best_candidate(*a, min, max);
		if (target < 0)
			return ;
		move_target(a, b, target);
	}
}

void	reconstruction(t_node **a, t_node **b)
{
	int	position;
	int	target;

	while (*b)
	{
		target = find_largest_index(*b);
		position = find_position(*b, target);
		if (position == 1 && (*b)->index == target - 1)
			sb(b);
		else
			bring_to_top_b(b, position);
		pa(a, b);
	}
}

void	custom_sort(t_node **a, t_node **b)
{
	int	size;

	if (!a || !*a || !b)
		return ;
	size = stack_size(*a);
	if (size >= 350)
	{
		complex_sort(a, b);
		return ;
	}
	if (count_inversions(*a) == 0)
		return ;
	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else if (size <= 5)
		sort_five(a, b);
	else
	{
		distribution(a, b);
		reconstruction(a, b);
	}
}
