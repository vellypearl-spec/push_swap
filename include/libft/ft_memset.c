/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_memset.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/06/28 21:41:39 by username         #+#    #+#              */
/*   Updated: 2026/07/05 12:10:25 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *ptr, int x, unsigned int n)
{
	unsigned char	*s;

	s = ptr;
	while (n--)
	{
		*s = (unsigned char) x;
		s++;
	}
	return (ptr);
}
