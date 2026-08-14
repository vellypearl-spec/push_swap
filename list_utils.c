/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 11:44:53 by vkuzmina          #+#    #+#             */
/*   Updated: 2026/08/14 14:46:35 by vkuzmina         ###   ########.fr       */
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

void	index_stack(t_node *a)
{
	t_node	*current;
	t_node	*checker;
	int		index;

	current = a;
	while (current)
	{
		checker = a;
		index = 0;
		while(checker)
		{
			if (checker->value < current->value)
			index++;
			checker = checker->next;
		}
		current->index = index;
		current = current->next;
	}
}
t_node	*find_last(t_node *a)
{
	t_node	*last_node;

	if (!a)
		return (NULL);
	last_node = a;
	while (last_node->next)
	{
		last_node = last_node->next;
	}
	return (last_node);
}
t_node	*find_before_last(t_node *a)
{
	t_node	*node_before;

	if (!a || a->next == NULL)
		return (NULL);
	node_before = a;
	while (node_before->next->next)
		node_before = node_before->next;
	return (node_before);
}
