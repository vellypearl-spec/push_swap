/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utility.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 20:34:39 by vkuzmina          #+#    #+#             */
/*   Updated: 2026/08/16 20:35:17 by vkuzmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_rotate(t_node **a, t_node **b, int start, int end)
{
	int	middle;
	int	index;

	middle = (start + end) / 2;
	index = (*a)->index;
	pb(a, b);
	if (index <= middle)
		rb(b);
}
