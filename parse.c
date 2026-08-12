/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 15:53:23 by vkuzmina          #+#    #+#             */
/*   Updated: 2026/08/12 16:07:54 by vkuzmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validation(char *str)
{
	int	i;

	i = 0;
	if (str[0]== '-' || str[0] == '+')
		i++;
	if (!str[i])
		return(0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return(0);
		else
			i++;
	}
	return (1);
}
