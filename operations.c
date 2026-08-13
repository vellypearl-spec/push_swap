/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 18:58:03 by vkuzmina          #+#    #+#             */
/*   Updated: 2026/08/13 19:30:32 by vkuzmina         ###   ########.fr       */
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
}