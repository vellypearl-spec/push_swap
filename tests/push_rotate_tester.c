/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rotate_tester.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 16:24:40 by vkuzmina          #+#    #+#             */
/*   Updated: 2026/08/16 16:50:09 by vkuzmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	if (argc < 2)
		return (1);

	a = NULL;
	b = NULL;

	stack_builder(&a, argc, argv);
	index_stack(a);

	ft_printf("Before:\n");
	ft_printf("A: ");
	print_stack(a);

	/* push_rotate(&a, &b, 0, 3);
	push_rotate(&a, &b, 0, 3);
	push_rotate(&a, &b, 0, 3);
	push_rotate(&a, &b, 0, 3);*/

	//push_rotate(&a, &b, 8, 9);
	//push_rotate(&a, &b, 8, 9);

	pb(&a, &b);
	ft_printf("After pb:\n");
	print_stack(b);
	pb(&a, &b);
	ft_printf("After pb:\n");
	print_stack(b);
	
	rb(&b);
	ft_printf("After rb:\n");
	print_stack(b);

	//ft_printf("\nAfter:\n");
	//ft_printf("A: ");
	//print_stack(a);
	//ft_printf("B: ");
	//print_stack(b);

	destroy_stack(&a);
	destroy_stack(&b);
	return (0);
}