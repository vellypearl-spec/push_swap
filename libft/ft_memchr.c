/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 20:25:45 by username          #+#    #+#             */
/*   Updated: 2026/07/01 20:45:47 by vkuzmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*s;

	i = 0;
	s = (unsigned char *) str;
	while (n > 0)
	{
		if (s[i] == (unsigned char) c)
			return ((&((unsigned char *) s)[i]));
		else
		{
			i++;
			n--;
		}
	}
	return (NULL);
}
