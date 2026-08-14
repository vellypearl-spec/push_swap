/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 11:35:21 by username          #+#    #+#             */
/*   Updated: 2026/07/21 12:06:58 by vkuzmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *check, ...)
{
	va_list			arg;
	unsigned int	i;
	int				indx;

	i = 0;
	indx = 0;
	va_start(arg, check);
	while (check[indx] != '\0')
	{
		if (check[indx] == '%')
		{
			if (check[indx +1] != '%')
				i += ft_checker (check[indx + 1], arg);
			else
				i += ft_printc('%');
			indx++;
		}
		else
			i = i + ft_printc(check[indx]);
		indx++;
	}
	va_end(arg);
	return (i);
}
