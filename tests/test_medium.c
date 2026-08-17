/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 17:47:46 by vkuzmina          #+#    #+#             */
/*   Updated: 2026/08/17 13:52:37 by vkuzmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;

	if (argc < 2)
		return (1);

	stack_builder(&a, argc, argv);
	index_stack(a);

	ft_printf("Before:\n");
	ft_printf("A: ");
	print_stack(a);
	ft_printf("B: ");
	print_stack(b);

	medium_sort(&a, &b);

	ft_printf("\nAfter first phase:\n");
	ft_printf("A: ");
	print_stack(a);
	ft_printf("B: ");
	print_stack(b);

	destroy_stack(&a);
	destroy_stack(&b);
	return (0);
}