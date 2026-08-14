/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 14:33:04 by vkuzmina          #+#    #+#             */
/*   Updated: 2026/08/14 15:13:26 by vkuzmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_node **a)
{
	t_node	*last_node;
	t_node	*node_before;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	node_before = find_before_last(*a);
	last_node = node_before->next;
	last_node->next = *a;
	node_before->next = NULL;
	*a = last_node;
}
void	rrb(t_node **b)
{
	t_node	*last_node;
	t_node	*node_before;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	node_before = find_before_last(*b);
	last_node = node_before->next;
	last_node->next = *b;
	node_before->next = NULL;
	*b = last_node;
}
void	rrr(t_node **a, t_node **b)
{
	rra(a);
	rrb(b);
}