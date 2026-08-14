/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 11:23:19 by username          #+#    #+#             */
/*   Updated: 2026/07/21 12:07:11 by vkuzmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_help(unsigned long val, int *l)

{
	char			*str;

	*l = 0;
	if (!val)
		*l = 1;
	else
		while (val && ++(*l))
			val /= 16;
	str = ft_calloc(*l + 1, sizeof(char));
	(*l)--;
	return (str);
}

int	ft_printp(unsigned long val, int ascii)
{
	char			*p;
	int				i;
	int				len;

	if (!val)
		return (ft_prints("(nil)"));
	p = ft_help(val, &i);
	if (!p)
		return (0);
	while (val)
	{
		if (val % 16 < 10)
			p[i--] = (val % 16) + '0';
		else
			p[i--] = (val % 16) + ascii;
		val /= 16;
	}
	len = ft_prints("0x") + ft_strlen(p);
	ft_putstr_fd(p, 1);
	free(p);
	return (len);
}
