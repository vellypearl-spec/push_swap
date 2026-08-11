/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printx_X.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 14:57:29 by vkuzmina          #+#    #+#             */
/*   Updated: 2026/07/21 12:08:13 by vkuzmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_helper(unsigned int val, int *l)

{
	int				i;
	unsigned int	vally;
	char			*str;

	vally = val;
	if (val == 0)
		i = 1;
	else
	{
		i = 0;
		while (vally != 0)
		{
			vally = vally / 16;
			i++;
		}
	}
	str = ft_calloc(i + 1, sizeof(char));
	if (!str)
		return (NULL);
	*l = i - 1;
	return (str);
}

int	cero(char *hex, unsigned int val)
{
	if (!hex)
		return (0);
	if (val == 0)
		hex[0] = '0';
	return (0);
}

int	ft_printhex(unsigned int val, int ascii)
{
	unsigned int	vally;
	char			*hex;
	int				i;
	int				*ihex;

	ihex = &i;
	vally = val;
	hex = ft_helper(val, ihex);
	cero (hex, val);
	while (vally != 0)
	{
		if ((vally % 16) < 10)
			hex[i] = (vally % 16) + 48;
		else
			hex[i] = (vally % 16) + ascii;
		vally = vally / 16;
		i--;
	}
	ft_putstr_fd(hex, 1);
	i = ft_strlen(hex);
	free(hex);
	return (i);
}
