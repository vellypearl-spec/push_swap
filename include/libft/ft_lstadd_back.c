/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 22:58:55 by username          #+#    #+#             */
/*   Updated: 2026/07/06 23:06:39 by vkuzmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*beginning;

	beginning = *lst;
	if (*lst)
	{
		while (beginning->next)
			beginning = beginning->next;
		beginning->next = new;
	}
	else
		*lst = new;
}
