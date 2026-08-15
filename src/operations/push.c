/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 18:58:03 by vkuzmina          #+#    #+#             */
/*   Updated: 2026/08/15 11:43:37 by vkuzmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_node **a, t_node **b)
{
	t_node	*node_to_push;
	t_node	*next_node;
    
	if(*a == NULL)
		return ;
	node_to_push = *a;
	next_node = (*a)->next;
	node_to_push->next = *b;
	*b = node_to_push;
	*a = next_node;
	g_operations++;
}

void    pa(t_node   **a, t_node **b)
{
	t_node	*node_to_push;
	t_node	*next_node;
    
	if(*b == NULL)
		return ;
	node_to_push = *b;
	next_node = (*b)->next;
	node_to_push->next = *a;
	*a = node_to_push;
	*b = next_node;
	g_operations++;
}
void	sa(t_node **a)
{
	t_node	*first_node;
	t_node	*second_node;
	t_node	*next_node;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	first_node = *a;
	second_node = (*a)->next;
	next_node = second_node->next;
	second_node->next = first_node;
	first_node->next = next_node;
	*a = second_node;
}
void	sb(t_node **b)
{
	t_node	*first_node;
	t_node	*second_node;
	t_node	*next_node;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	first_node = *b;
	second_node = (*b)->next;
	next_node = second_node->next;
	second_node->next = first_node;
	first_node->next = next_node;
	*b = second_node;
}
void	ss(t_node **a, t_node **b)
{
	sa(a);
	sb(b);
}