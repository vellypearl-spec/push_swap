/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 13:34:48 by vkuzmina          #+#    #+#             */
/*   Updated: 2026/07/13 12:20:46 by vkuzmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t s)
{
	size_t		i;
	int			x;
	size_t		dst_len;
	size_t		src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = dst_len;
	x = 0;
	if (s <= (size_t) dst_len)
		return (s + src_len);
	while ((i + x) < (s - 1) && src[x] != '\0')
	{
		dst[i + x] = src[x];
		x++;
	}
	dst[i + x] = '\0';
	return (dst_len + src_len);
}
