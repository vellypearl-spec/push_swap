/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 18:19:19 by vkuzmina          #+#    #+#             */
/*   Updated: 2026/08/18 10:26:09 by vkuzmina         ###   ########.fr       */
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