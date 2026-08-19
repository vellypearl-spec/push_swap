/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 18:19:19 by vkuzmina          #+#    #+#             */
/*   Updated: 2026/08/19 14:38:39 by vkuzmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotation_cost(int size, int position)
{
	int	cost;

	if (position < size - position)
		cost = position;
	else
		cost = size - position;
	return (cost);
}

int	candidate_cost(t_node *a, int index)
{
	int	size;
	int	cost;
	int	position;

	position = find_position(a, index);
	if (position < 0)
		return (-1);
	size = stack_size(a);
	cost = rotation_cost(size, position) + 1;
	return (cost);
}

int	hitchike(t_node *a, t_node *b, int a_position, int b_position)
{
	int	a_cost;
	int	b_cost;
	int	a_direction;
	int	b_direction;
	int	bigger_cost;

	a_cost = rotation_cost(stack_size(a), a_position);
	b_cost = rotation_cost(stack_size(b), b_position);
	a_direction = rotation_direction(stack_size(a), a_position);
	b_direction = rotation_direction(stack_size(b), b_position);
	if (a_direction == b_direction)
	{
		if (a_cost > b_cost)
			bigger_cost = a_cost;
		else
			bigger_cost = b_cost;
		return (bigger_cost);
	}
	return (a_cost + b_cost);
}
