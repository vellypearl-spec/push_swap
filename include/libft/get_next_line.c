/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 16:11:38 by vkuzmina          #+#    #+#             */
/*   Updated: 2026/07/28 12:51:19 by vkuzmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	make_list(t_gnl_list **list, int fd)
{
	int			chars;
	char		*buf;
	t_gnl_list	*last;

	last = lstlast(*list);
	while (!checker(last))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
			return ;
		chars = read(fd, buf, BUFFER_SIZE);
		if (!chars)
		{
			free(buf);
			return ;
		}
		buf[chars] = '\0';
		add(list, &last, buf);
	}
}

void	add(t_gnl_list **list, t_gnl_list **last, char *buf)
{
	t_gnl_list	*node;

	node = malloc(sizeof(t_gnl_list));
	if (!node)
	{
		free(buf);
		return ;
	}
	node->buffer = buf;
	node->next_str = NULL;
	if (!*list)
		*list = node;
	else
		(*last)->next_str = node;
	*last = node;
}

char	*get_line(t_gnl_list *list)
{
	int		length;
	char	*next;

	if (list == NULL)
		return (NULL);
	length = newline_length(list);
	next = malloc(length + 1);
	if (next == NULL)
		return (NULL);
	copy (list, next);
	return (next);
}

void	clear(t_gnl_list **list)
{
	t_gnl_list	*last_node;
	t_gnl_list	*node;
	char		*buff;
	int			i;
	int			l;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return ;
	node = malloc(sizeof(t_gnl_list));
	if (!node)
		return (free(buff));
	i = 0;
	l = 0;
	last_node = lstlast(*list);
	while (last_node -> buffer[i] && last_node -> buffer[i] != '\n')
		++i;
	while (last_node -> buffer[i] && last_node -> buffer[++i])
		buff[l++] = last_node -> buffer[i];
	buff[l] = '\0';
	node->buffer = buff;
	node->next_str = NULL;
	freedom(list, node, buff);
}

char	*get_next_line(int fd)
{
	static t_gnl_list	*list;
	char				*next;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next, 0) < 0)
		return (NULL);
	make_list(&list, fd);
	if (list == NULL)
		return (NULL);
	next = get_line(list);
	clear(&list);
	return (next);
}
