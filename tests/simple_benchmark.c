/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_benchmark.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 11:31:55 by vkuzmina          #+#    #+#             */
/*   Updated: 2026/08/17 16:33:44 by vkuzmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*int	main(int argc, char **argv)
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
	medium_sort(&a, &b);
	printf("size: %d | disorder: %.6f | operations: %d\n",
		stack_size(a), disorder, g_operations);
	destroy_stack(&a);
	destroy_stack(&b);
	return (0);
}*/

/*int main(int argc, char **argv)
{
	t_node	*a;
	double	disorder;

	a = NULL;
	stack_builder(&a, argc, argv);
	index_stack(a);

	disorder = calculate_disorder(a);

	printf("disorder: %.6f\n", disorder);

	destroy_stack(&a);
	return (0);
}*/
int	main(int argc, char **argv)
{
	t_node	*a_medium_new;
	t_node	*b_medium_new;
	t_node	*a_medium;
	t_node	*b_medium;
	double	disorder;

	a_medium_new = NULL;
	b_medium_new = NULL;
	a_medium = NULL;
	b_medium = NULL;

	stack_builder(&a_medium_new, argc, argv);
	stack_builder(&a_medium, argc, argv);

	index_stack(a_medium_new);
	index_stack(a_medium);

	disorder = calculate_disorder(a_medium_new);

	g_operations = 0;
	medium_sort(&a_medium_new, &b_medium_new);
	printf("Optimized medium sort: %d operations\n", g_operations);

	g_operations = 0;
	medium_sort_old(&a_medium, &b_medium);
	printf("Old medium sort: %d operations\n", g_operations);

	printf("Size: %d | Disorder: %.6f\n",
		argc - 1, disorder);

	destroy_stack(&a_medium_new);
	destroy_stack(&b_medium_new);
	destroy_stack(&a_medium);
	destroy_stack(&b_medium);
	return (0);
}
