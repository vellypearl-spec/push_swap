/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 12:46:37 by vkuzmina          #+#    #+#             */
/*   Updated: 2026/08/19 13:54:03 by vkuzmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	main(int argc, char **argv)
{
	t_node		*a;
	t_node		*b;
	t_strategy	strategy;
	int			bench;
	int			first;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	first = parse_flags(argc, argv, &strategy, &bench);
	if (first == argc)
		return (0);
	stack_builder(&a, argc - first + 1, argv + first - 1);
	run_strategy(strategy, &a, &b);
	(void)bench;
	destroy_stack(&a);
	destroy_stack(&b);
	return (0);
}
