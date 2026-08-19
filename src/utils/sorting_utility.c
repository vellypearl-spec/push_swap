/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utility.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 20:34:39 by vkuzmina          #+#    #+#             */
/*   Updated: 2026/08/19 14:40:02 by vkuzmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_rotate(t_node **a, t_node **b, int start, int end)
{
	int	middle;
	int	index;

	middle = (start + end) / 2;
	index = (*a)->index;
	pb(a, b);
	if (index <= middle)
		rb(b);
}

void	bring_to_top_b(t_node **b, int position)
{
	int		size;
	int		rotation;

	size = stack_size(*b);
	rotation = rotation_cost(size, position);
	if (position <= size / 2)
	{
		while (position)
		{
			rb(b);
			--position;
		}
	}
	else
	{
		while (rotation)
		{
			rrb(b);
			--rotation;
		}
	}
}

int	rotation_direction(int size, int position)
{
	if (position == 0)
		return (0);
	if (position <= size / 2)
		return (1);
	return (-1);
}

void	execute_hitchike(t_node **a, t_node **b,
		int a_position, int b_position)
{
	int	a_cost;
	int	b_cost;
	int	rotation;

	a_cost = rotation_cost(stack_size(*a), a_position);
	b_cost = rotation_cost(stack_size(*b), b_position);
	rotation = rotation_direction(stack_size(*a), a_position);
	while (a_cost > 0 && b_cost > 0)
	{
		if (rotation == 1)
			rr(a, b);
		else if (rotation == -1)
			rrr(a, b);
		a_cost--;
		b_cost--;
	}
	while (a_cost > 0)
	{
		if (rotation == 1)
			ra(a);
		else if (rotation == -1)
			rra(a);
		a_cost--;
	}
}
