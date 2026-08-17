/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 13:21:07 by vkuzmina          #+#    #+#             */
/*   Updated: 2026/08/17 14:12:38 by vkuzmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	g_operations++;
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
	g_operations++;
}

void	ss(t_node **a, t_node **b)
{
	sa(a);
	sb(b);
	g_operations++;
}

