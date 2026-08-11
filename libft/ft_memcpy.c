/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_memcpy.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/06/29 11:36:51 by username         #+#    #+#              */
/*   Updated: 2026/07/05 21:49:52 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memcpy(void *to, const void *from, unsigned int n)
{
	unsigned char	*t;
	unsigned char	*f;
	unsigned int	i;

	t = (unsigned char *) to;
	f = (unsigned char *) from;
	i = 0;
	while (i < n)
	{
		if (t != NULL || f != NULL)
		{
			t[i] = f[i];
		}
		i++;
	}
	return (t);
}
