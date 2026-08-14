/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_strategy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 18:47:31 by vkuzmina          #+#    #+#             */
/*   Updated: 2026/08/14 19:53:16 by vkuzmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	bubble_pass(t_node **a)
{
	t_node	*current;
	t_node	*next_node;
	int		size;

	if (!*a)
		return ;
	size = stack_size(*a) - 1;
	current = *a;
	next_node = (*a)->next;
	while (size)
	{
		if (current->index > next_node->index)
			sa(a);
		ra(a);
		current = *a;
		next_node = (*a)->next;
		--size;
	}
}*/
void	simple_sort(t_node **a, t_node **b)
{
	int	size;
	int	position;
	int	smallest;

	size = stack_size(*a);
	smallest = 0;
	while (size)
	{
		position = find_position(*a, smallest);
		bring_to_top(a, position);
		pb(a, b);
		++smallest;
		--size;
	}
	size = stack_size(*b);
	while (size)
	{
		pa(a, b);
		--size;
	}
}
