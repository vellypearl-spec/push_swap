/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_benchmark.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 11:31:55 by vkuzmina          #+#    #+#             */
/*   Updated: 2026/08/16 15:14:47 by vkuzmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	double	disorder;

	a = NULL;
	b = NULL;
	stack_builder(&a, argc, argv);
	index_stack(a);
	disorder = calculate_disorder(a);
	g_operations = 0;
	simple_sort(&a, &b);
	printf("size: %d | disorder: %.3f | operations: %d\n",
		stack_size(a), disorder, g_operations);
	destroy_stack(&a);
	destroy_stack(&b);
	return (0);
}
