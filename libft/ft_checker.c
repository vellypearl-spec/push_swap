/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 11:40:22 by username          #+#    #+#             */
/*   Updated: 2026/07/21 12:08:36 by vkuzmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_checker(const char check, va_list arg)
{
	int	i;

	i = 0;
	if (check == 'c')
		i += ft_printc(va_arg(arg, int));
	else if (check == 'd' || check == 'i')
		i += ft_printd_i(va_arg(arg, int));
	else if (check == 'p')
		i += ft_printp(va_arg(arg, unsigned long), 87);
	else if (check == 's')
		i += ft_prints(va_arg(arg, char *));
	else if (check == 'u')
		i += ft_printu(va_arg(arg, unsigned int));
	else if (check == 'x')
		i += ft_printhex(va_arg(arg, unsigned int), 87);
	else if (check == 'X')
		i += ft_printhex (va_arg(arg, unsigned int), 55);
	return (i);
}
