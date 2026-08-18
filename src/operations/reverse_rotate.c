/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 14:33:04 by vkuzmina          #+#    #+#             */
/*   Updated: 2026/08/18 21:27:20 by vkuzmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	r_rotate(t_node **stack)
{
	t_node	*last_node;
	t_node	*node_before;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	node_before = find_before_last(*stack);
	last_node = node_before->next;
	last_node->next = *stack;
	node_before->next = NULL;
	*stack = last_node;
}

void	rra(t_node **a)
{
	r_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_node **b)
{
	r_rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_node **a, t_node **b)
{
	r_rotate(a);
	r_rotate(b);
	ft_printf("rrr\n");
}
