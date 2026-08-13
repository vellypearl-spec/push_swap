/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 12:46:37 by vkuzmina          #+#    #+#             */
/*   Updated: 2026/08/13 18:10:05 by vkuzmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*current;

	a = NULL;
	stack_builder(&a, argc, argv);

	current = a;
	while (current)
	{
		printf("value: %d | index: %d\n",
			current->value, current->index);
		current = current->next;
	}

	destroy_stack(&a);
	return (0);
}