/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 12:46:37 by vkuzmina          #+#    #+#             */
/*   Updated: 2026/08/18 21:25:27 by vkuzmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	stack_builder(&a, argc, argv);
	duplicate_checker(a);
	index_stack(a);
	custom_sort(&a, &b);
	destroy_stack(&a);
	destroy_stack(&b);
	return (0);
}
