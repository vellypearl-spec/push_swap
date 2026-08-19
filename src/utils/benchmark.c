/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 16:28:10 by vkuzmina          #+#    #+#             */
/*   Updated: 2026/08/19 17:03:51 by vkuzmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_disorder(t_node *a)
{
	int	value;
	int	decimal;

	value = (int)(calculate_disorder(a) * 10000.0 + 0.5);
	decimal = value % 100;
	ft_putstr_fd("Disorder: ", 2);
	ft_putnbr_fd(value / 100, 2);
	ft_putchar_fd('.', 2);
	if (decimal < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(decimal, 2);
	ft_putstr_fd("%\n", 2);
}

static void	print_strategy(t_strategy strategy)
{
	if (strategy == SIMPLE)
		ft_putstr_fd("Strategy: simple | O(n^2)\n", 2);
	else if (strategy == MEDIUM)
		ft_putstr_fd("Strategy: medium | O(n*sqrt(n))\n", 2);
	else if (strategy == COMPLEX)
		ft_putstr_fd("Strategy: complex | O(n log n)\n", 2);
	else if (strategy == ADAPTIVE)
		ft_putstr_fd("Strategy: adaptive | hybrid\n", 2);
}

void	print_benchmark(t_strategy strategy, t_node *a)
{
	print_disorder(a);
	print_strategy(strategy);
}
