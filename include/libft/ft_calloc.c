/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_calloc.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/07/02 23:41:20 by username         #+#    #+#              */
/*   Updated: 2026/07/05 14:21:36 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

void	*ft_calloc(size_t amount, size_t size)
{
	char	*str;

	if (amount <= 0 || size <= 0)
	{
		str = (char *) malloc(1);
	}
	else
	{
		str = (char *) malloc(amount * size);
	}
	if (!str)
		return (NULL);
	return (ft_memset(str, 0, amount * size));
}
