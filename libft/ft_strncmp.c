/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 14:54:24 by username          #+#    #+#             */
/*   Updated: 2026/07/07 19:04:12 by vkuzmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(char *str1, char *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (n > i)
	{
		if (str1[i] == '\0' || str2[i] == '\0')
			return ((unsigned char) str1[i] - (unsigned char) str2[i]);
		else if (str1[i] != str2[i])
			return ((unsigned char) str1[i] - (unsigned char) str2[i]);
		i++;
	}
	return (0);
}
