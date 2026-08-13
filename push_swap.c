/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 12:46:37 by vkuzmina          #+#    #+#             */
/*   Updated: 2026/08/13 19:32:19 by vkuzmina         ###   ########.fr       */
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

	while(a)
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
	}
	while(b)
	{
		ft_printf("BEFORE:\n");
		ft_printf("A: ");
		print_stack(a);
		ft_printf("B: ");
		print_stack(b);
		pa(&a, &b);
		ft_printf("\nAFTER pb:\n");
		ft_printf("A: ");
		print_stack(a);
		ft_printf("B: ");
		print_stack(b);
	}
	destroy_stack(&a);
	destroy_stack(&b);
	return (0);
}