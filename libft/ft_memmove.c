/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 13:01:05 by username          #+#    #+#             */
/*   Updated: 2026/07/01 14:27:22 by vkuzmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dest, const void *src, unsigned int n)
{
	char	*d;
	char	*s;

	d = (char *) dest;
	s = (char *) src;
	if (dest <= src)
	{
		while (n--)
		{
			*d++ = *s++;
		}
	}
	else if (dest > src)
	{
		d += n - 1;
		s += n - 1;
		while (n--)
		{
			*d-- = *s--;
		}
	}
	return (dest);
}
