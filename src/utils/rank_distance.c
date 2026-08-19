/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank_distance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 20:24:40 by vkuzmina          #+#    #+#             */
/*   Updated: 2026/08/19 14:39:42 by vkuzmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	rank_distance(t_node *a)
{
	int		index;
	int		size;
	int		total_distance;
	double	rank;

	index = 0;
	size = stack_size(a);
	total_distance = 0;
	if (size < 2)
		return (0.0);
	while (index < size - 1)
	{
		total_distance += rank_pair_distance(a, index, size);
		++index;
	}
	rank = (double)total_distance / (size - 1);
	return (rank);
}

int	direct_distance(int position_current, int position_next)
{
	int	d_distance;

	d_distance = position_current - position_next;
	if (d_distance < 0)
		d_distance = -d_distance;
	return (d_distance);
}

int	circular_distance(int d_distance, int size)
{
	int	c_distance;

	if (d_distance < size - d_distance)
		c_distance = d_distance;
	else
		c_distance = size - d_distance;
	return (c_distance);
}

int	rank_pair_distance(t_node *a, int index, int size)
{
	int		position_current;
	int		position_next;
	int		d_distance;
	int		c_distance;

	position_current = find_position(a, index);
	position_next = find_position(a, index + 1);
	d_distance = direct_distance(position_current, position_next);
	c_distance = circular_distance(d_distance, size);
	return (c_distance);
}
