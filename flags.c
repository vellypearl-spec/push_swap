/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glouis <glouis@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 00:00:00 by glouis            #+#    #+#             */
/*   Updated: 2026/08/18 00:00:00 by glouis           ###   ########.fr       */
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

/*
** Temporary stand-in for the custom/adaptive strategy while it's still
** being built: dispatches to one of the three fixed strategies based on
** the disorder thresholds defined in the subject. Swap this out once
** custom_strategy() is finished.
*/
static void	adaptive_dispatch(t_node **a, t_node **b)
{
	double	disorder;

	disorder = calculate_disorder(*a);
	if (disorder < 0.2)
		simple_strategy(a, b);
	else if (disorder < 0.5)
		medium_sort(a, b);
	else
		complex_sort(a, b);
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
		adaptive_dispatch(a, b);
}
