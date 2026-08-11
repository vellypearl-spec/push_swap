/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 12:41:03 by vkuzmina          #+#    #+#             */
/*   Updated: 2026/07/21 12:07:59 by vkuzmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	helpie(unsigned int uu)
{
	if (uu > 9)
		ft_printu(uu / 10);
	if (uu <= 9)
	{
		ft_putchar_fd(uu + 48, 1);
		return ;
	}
	ft_putchar_fd((uu % 10) + 48, 1);
}

int	ft_printu(unsigned int u)
{
	unsigned int	i;

	helpie(u);
	i = 1;
	while (u > 9)
	{
		u = u / 10;
		i++;
	}
	return (i);
}
