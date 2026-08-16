/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 18:19:19 by vkuzmina          #+#    #+#             */
/*   Updated: 2026/08/16 15:13:06 by vkuzmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotation_cost(int size, int position)
{
	int	cost;

	if (position < size - position)
		cost = position;
	else
		cost = size - position;
	return (cost);
}
