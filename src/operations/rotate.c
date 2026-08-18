/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 14:02:19 by vkuzmina          #+#    #+#             */
/*   Updated: 2026/08/18 21:27:37 by vkuzmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_node **stack)
{
	t_node	*first_node;
	t_node	*last_node;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first_node = *stack;
	last_node = find_last(*stack);
	last_node->next = first_node;
	*stack = first_node->next;
	first_node->next = NULL;
}
void	ra(t_node **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_node **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
