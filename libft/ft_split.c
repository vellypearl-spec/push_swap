/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 17:53:03 by username          #+#    #+#             */
/*   Updated: 2026/07/06 20:10:34 by vkuzmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wrdcnt(const char *str, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] != c && str[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	**ft_fillup(char **aos, char const *str, char c)
{
	size_t	i;
	size_t	l;
	int		indx;
	size_t	str_len;

	i = 0;
	indx = 0;
	str_len = ft_strlen(str);
	while (str[i])
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		l = i;
		while (str[i] != c && str[i] != '\0')
			i++;
		if (l >= str_len)
			aos[indx++] = "\0";
		else
			aos[indx++] = ft_substr(str, l, i - l);
	}
	return (aos);
}

char	**ft_split(char const *s, char c)
{
	char	**aos;
	int		nw;

	if (!s)
		return (NULL);
	nw = ft_wrdcnt(s, c);
	aos = malloc((nw + 1) * sizeof(char *));
	if (aos == NULL)
		return (NULL);
	aos = ft_fillup(aos, s, c);
	aos[nw] = NULL;
	return (aos);
}
