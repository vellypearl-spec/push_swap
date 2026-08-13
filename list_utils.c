/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 11:44:53 by vkuzmina          #+#    #+#             */
/*   Updated: 2026/08/13 12:24:59 by vkuzmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int n)
{
	t_node	*node;

	node = ft_calloc(1, sizeof(t_node));
	if (!node)
		return (NULL);
	node -> value = n;
	node -> index = -1;
	node -> next = NULL;
	return (node);
}

void	destroy_stack(t_node **a)
{
	t_node	*current;

	while (*a)
	{
		current = (*a)->next;
		free(*a);
		*a = current;
	}
}
void	add_back(t_node **a, t_node *new)
{
	t_node	*current;
	
	if (!new)
		return ;
	current = *a;
	if (*a)
	{
		while (current->next)
			current = current->next;
		current->next = new;
	}
	else
		*a = new;
}
