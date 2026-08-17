/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utility.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 20:34:39 by vkuzmina          #+#    #+#             */
/*   Updated: 2026/08/17 14:39:46 by vkuzmina         ###   ########.fr       */
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
