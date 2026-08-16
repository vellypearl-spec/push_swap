/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 15:27:32 by vkuzmina          #+#    #+#             */
/*   Updated: 2026/08/16 15:11:23 by vkuzmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_node **a)
{
	t_node	*first_node;
	t_node	*second_node;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	first_node = *a;
	second_node = (*a)->next;
	if (first_node->value > second_node->value)
		sa(a);
	return ;
}

void	sort_three(t_node **a)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (!*a || !(*a)->next)
		return ;
	if (!(*a)->next->next)
	{
		sort_two(a);
		return ;
	}
	first = *a;
	second = (*a)->next;
	third = (*a)->next->next;
	if (first->index > second->index && first->index > third->index)
	{
		ra(a);
		sort_two(a);
	}
	else if (second->index > first->index && second->index > third->index)
	{
		rra(a);
		sort_two(a);
	}
	else
		sort_two(a);
}

void	sort_five(t_node **a, t_node **b)
{
	int		index;
	int		position;

	if (!*a || !(*a)->next)
		return ;
	if (!(*a)->next->next)
	{
		sort_two(a);
		return ;
	}
	index = 0;
	position = find_position(*a, index);
	bring_to_top(a, position);
	pb(a, b);
	index = 1;
	position = find_position(*a, index);
	bring_to_top(a, position);
	pb(a, b);
	sort_three(a);
	pa(a, b);
	pa(a, b);
}
