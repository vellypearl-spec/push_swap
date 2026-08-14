/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 12:46:37 by vkuzmina          #+#    #+#             */
/*   Updated: 2026/08/14 21:34:53 by vkuzmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	int		size;
	int		inversions;
	double	disorder;

	if (argc < 2)
	{
		ft_printf("Usage: ./test <numbers>\n");
		return (1);
	}

	a = NULL;

	stack_builder(&a, argc, argv);
	ft_printf("Stack built\n");

	index_stack(a);
	ft_printf("Stack indexed\n");

	size = stack_size(a);
	ft_printf("Size: %d\n", size);

	inversions = count_inversions(a);
	ft_printf("Inversions: %d\n", inversions);

	disorder = calculate_disorder(a);
	printf("Disorder: %f\n", disorder);

	destroy_stack(&a);
	return (0);
}
