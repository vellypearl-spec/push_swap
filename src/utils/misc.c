/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 10:14:58 by vkuzmina          #+#    #+#             */
/*   Updated: 2026/08/20 10:21:12 by vkuzmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(t_node **a)
{
	if (a)
		destroy_stack(a);
	write(2, "Error\n", 6);
	exit(1);
}

int	sign(char *str)
{
	if (*str == '-')
		return (-1);
	else
		return (1);
}

void	print_stack(t_node *stack)
{
	while (stack)
	{
		ft_printf("%d ", stack->value);
		stack = stack->next;
	}
	ft_printf("\n");
}

int	stack_size(t_node *a)
{
	int	size;

	size = 0;
	while (a)
	{
		size++;
		a = a->next;
	}
	return (size);
}
