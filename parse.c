/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 15:53:23 by vkuzmina          #+#    #+#             */
/*   Updated: 2026/08/13 11:43:02 by vkuzmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validation(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		else
			i++;
	}
	return (1);
}

long	conversion_range(char *str)
{
	long	number;
	int		i;
	long	limit;

	i = 0;
	number = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (str[0] == '-')
		limit = 2147483648;
	else 
		limit = 2147483647;
	while (str[i])
	{
		if (number > ((limit - (str[i]-'0'))/10))
			error();
		else
		{
			number = number*10 + (str[i] - '0');
			i++;
		}
	}
	number = sign(str) * number;
	return (number);
}
int	sign(char *str)
{
	if (*str == '-')
		return (-1);
	else
		return (1);
}