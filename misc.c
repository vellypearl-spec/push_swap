/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 10:14:58 by vkuzmina          #+#    #+#             */
/*   Updated: 2026/08/13 17:23:18 by vkuzmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void error(void)
{
    ft_printf("Oops, seems there is an error! ( : o ‸ o : )\n");
    exit (0);
}

int	sign(char *str)
{
	if (*str == '-')
		return (-1);
	else
		return (1);
}