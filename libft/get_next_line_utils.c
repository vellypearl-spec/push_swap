/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 13:37:49 by vkuzmina          #+#    #+#             */
/*   Updated: 2026/07/28 12:51:39 by vkuzmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	checker(t_gnl_list *last)
{
	int	i;

	if (!last)
		return (0);
	i = 0;
	while (last->buffer[i])
	{
		if (last->buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

t_gnl_list	*lstlast(t_gnl_list *list)
{
	if (list == NULL)
		return (NULL);
	while (list -> next_str)
	{
		list = list -> next_str;
	}
	return (list);
}

void	copy(t_gnl_list *list, char *s)
{
	int	i;
	int	l;

	l = 0;
	if (list == NULL)
		return ;
	while (list)
	{
		i = 0;
		while (list -> buffer[i])
		{
			if (list -> buffer[i] == '\n')
			{
				s[l++] = '\n';
				s[l] = '\0';
				return ;
			}
			s[l++] = list -> buffer[i++];
		}
		list = list -> next_str;
	}
	s[l] = '\0';
}

int	newline_length(t_gnl_list *list)
{
	int	i;
	int	l;

	if (list == NULL)
		return (0);
	l = 0;
	while (list)
	{
		i = 0;
		while (list -> buffer[i])
		{
			if (list -> buffer[i] == '\n')
			{
				++l;
				return (l);
			}
			++i;
			++l;
		}
		list = list -> next_str;
	}
	return (l);
}

void	freedom(t_gnl_list **list, t_gnl_list *node, char *buff)
{
	t_gnl_list	*reminder;

	if (*list == NULL)
		return ;
	while (*list)
	{
		reminder = (*list)->next_str;
		free((*list)->buffer);
		free(*list);
		*list = reminder;
	}
	if (node -> buffer[0])
		*list = node;
	else
	{
		free(buff);
		free(node);
	}
}
