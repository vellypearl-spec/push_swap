/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strdup.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/07/05 11:24:22 by username         #+#    #+#              */
/*   Updated: 2026/07/05 22:19:37 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strdup(char *s)
{
	char	*copy;
	size_t	length;

	if (!s)
		return (NULL);
	length = ft_strlen(s);
	copy = (char *) malloc(length + 1);
	if (!copy)
		return (NULL);
	ft_strlcpy(copy, s, length + 1);
	return (copy);
}
