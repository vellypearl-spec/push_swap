/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 12:46:37 by vkuzmina          #+#    #+#             */
/*   Updated: 2026/08/14 15:11:37 by vkuzmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;

	add_back(&a, create_node(1));
	add_back(&a, create_node(2));
	add_back(&a, create_node(3));
	add_back(&a, create_node(4));
	add_back(&b, create_node(5));
	add_back(&b, create_node(6));
	add_back(&b, create_node(7));
	add_back(&b, create_node(8));

	ft_printf("BEFORE:\n");
	ft_printf("A: ");
	print_stack(a);
	ft_printf("B: ");
	print_stack(b);
	rrr(&a, &b);
	ft_printf("\nAFTER ra:\n");
	ft_printf("A: ");
	print_stack(a);
	ft_printf("B: ");
	print_stack(b);
	ft_printf("BEFORE:\n");
	ft_printf("A: ");
	print_stack(a);
	ft_printf("B: ");
	print_stack(b);
	rrr(&a, &b);
	ft_printf("\nAFTER ra:\n");
	ft_printf("A: ");
	print_stack(a);
	ft_printf("B: ");
	print_stack(b);
	ft_printf("BEFORE:\n");
	ft_printf("A: ");
	print_stack(a);
	ft_printf("B: ");
	print_stack(b);
	rrr(&a, &b);
	ft_printf("\nAFTER ra:\n");
	ft_printf("A: ");
	print_stack(a);
	ft_printf("B: ");
	print_stack(b);
	ft_printf("BEFORE:\n");
	ft_printf("A: ");
	print_stack(a);
	ft_printf("B: ");
	print_stack(b);
	rrr(&a, &b);
	ft_printf("\nAFTER ra:\n");
	ft_printf("A: ");
	print_stack(a);
	ft_printf("B: ");
	print_stack(b);
	ft_printf("BEFORE:\n");
	ft_printf("A: ");
	print_stack(a);
	ft_printf("B: ");
	print_stack(b);
	rrr(&a, &b);
	ft_printf("\nAFTER ra:\n");
	ft_printf("A: ");
	print_stack(a);
	ft_printf("B: ");
	print_stack(b);
	
	//ft_printf("B: ");
	//print_stack(b);
	/* while(a)
	{
		ft_printf("BEFORE:\n");
		ft_printf("A: ");
		print_stack(a);
		ft_printf("B: ");
		print_stack(b);
		pb(&a, &b);
		ft_printf("\nAFTER pb:\n");
		ft_printf("A: ");
		print_stack(a);
		ft_printf("B: ");
		print_stack(b);
	} */
	destroy_stack(&a);
	//destroy_stack(&b);
	return (0);
}