/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 21:40:21 by username          #+#    #+#             */
/*   Updated: 2026/07/01 21:50:17 by vkuzmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	const char		*s1;
	const char		*s2;
	unsigned int	i;

	s1 = (const char *) str1;
	s2 = (const char *) str2;
	i = 0;
	while (n > 0)
	{
		if (s1[i] != s2[i])
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		else
		{
			i++;
			n--;
		}
	}
	return (0);
}
