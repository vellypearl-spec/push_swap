/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 14:10:21 by username          #+#    #+#             */
/*   Updated: 2026/07/07 18:25:24 by vkuzmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *str, int c)
{
	int	end;

	end = ft_strlen(str) - 1;
	if (c == '\0')
		return ((char *) & str[ft_strlen(str)]);
	while (end >= 0)
	{
		if (str[end] == c)
			return ((char *) & str[end]);
		else
			end--;
	}
	if (end < 0)
		return (NULL);
	return (NULL);
}
