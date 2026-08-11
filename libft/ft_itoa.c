/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 20:43:06 by username          #+#    #+#             */
/*   Updated: 2026/07/06 21:00:33 by vkuzmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_length(long num)
{
	size_t	l;

	l = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		l++;
		num = -num;
	}
	while (num >= 1)
	{
		l++;
		num /= 10;
	}
	return (l);
}

static char	*ft_greatconversion(long num, char *str, size_t l)
{
	str = ft_calloc(l + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	l--;
	while (l)
	{
		str[l] = (num % 10) + '0';
		num /= 10;
		l--;
	}
	if (str[0] != '-')
	{
		str[0] = (num % 10) + '0';
	}
	return (str);
}

char	*ft_itoa(int n)
{
	long	num;
	size_t	l;
	char	*str;

	num = n;
	l = ft_length(num);
	str = 0;
	str = ft_greatconversion(num, str, l);
	if (!str)
		return (NULL);
	return (str);
}
