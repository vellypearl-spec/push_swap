/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_metric.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 20:22:08 by vkuzmina          #+#    #+#             */
/*   Updated: 2026/08/14 20:47:00 by vkuzmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_inversions(t_node *a)
{
	t_node	*current;
	t_node	*compare;
	int		inversion;

	current = a;
	inversion = 0;
	while (current)
	{
		compare = current->next;
		while (compare)
		{
			if (current->index > compare->index)
				++inversion;
			compare = compare->next;
		}
		current = current->next;
	}
	return(inversion);
}
double	calculate_disorder(t_node *a)
{
	int		size;
	int		inversion;
	int		max;
	double	disorder;

	size = stack_size(a);
	if (size < 2)
		return (0.0);
	inversion = count_inversions(a);
	max = (size * (size - 1)) / 2;
	disorder = (double)inversion / max;
	return (disorder);
}