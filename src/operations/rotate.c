/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 14:02:19 by vkuzmina          #+#    #+#             */
/*   Updated: 2026/08/14 14:30:45 by vkuzmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **a)
{
	t_node 	*first_node;
	t_node 	*last_node;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	first_node = *a;
	last_node = find_last(*a);
	last_node->next = first_node;
	*a = first_node->next;
	first_node->next = NULL;
}
void	rb(t_node **b)
{
	t_node 	*first_node;
	t_node 	*last_node;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	first_node = *b;
	last_node = find_last(*b);
	last_node->next = first_node;
	*b = first_node->next;
	first_node->next = NULL;
}
void	rr(t_node **a, t_node **b)
{
	ra(a);
	rb(b);
}