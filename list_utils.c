/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 11:44:53 by vkuzmina          #+#    #+#             */
/*   Updated: 2026/08/12 13:44:29 by vkuzmina         ###   ########.fr       */
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

void	freedom(t_node **a)
{
	t_node	*current;

	while (*a)
	{
		current = (*a)->next;
		free(*a);
		*a = current;
	}
}
