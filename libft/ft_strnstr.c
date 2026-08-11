/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 12:49:31 by username          #+#    #+#             */
/*   Updated: 2026/07/07 19:19:37 by vkuzmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned char	i;
	unsigned char	x;

	i = 0;
	x = 0;
	if (little[i] == '\0')
		return ((char *) big);
	while (big[i] != '\0' && i < len)
	{
		while (big[i + x] == little[x] && i + x < len && little[x] != '\0')
			x++;
		if (little[x] == '\0')
			return ((char *) big + i);
		i++;
		x = 0;
	}
	return (NULL);
}
