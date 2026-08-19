/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glouis <glouis@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 11:33:41 by glouis            #+#    #+#             */
/*   Updated: 2026/08/19 11:33:41 by glouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_flags(int argc, char **argv, t_strategy *strategy, int *bench)
{
	int	i;

	*strategy = ADAPTIVE;
	*bench = 0;
	i = 1;
	while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (!ft_strncmp(argv[i], "--simple", 9))
			*strategy = SIMPLE;
		else if (!ft_strncmp(argv[i], "--medium", 9))
			*strategy = MEDIUM;
		else if (!ft_strncmp(argv[i], "--complex", 10))
			*strategy = COMPLEX;
		else if (!ft_strncmp(argv[i], "--adaptive", 11))
			*strategy = ADAPTIVE;
		else if (!ft_strncmp(argv[i], "--bench", 8))
			*bench = 1;
		else
			error();
		i++;
	}
	return (i);
}

void	run_strategy(t_strategy strategy, t_node **a, t_node **b)
{
	if (strategy == SIMPLE)
		simple_strategy(a, b);
	else if (strategy == MEDIUM)
		medium_sort(a, b);
	else if (strategy == COMPLEX)
		complex_sort(a, b);
	else
		custom_sort(a, b);
}
