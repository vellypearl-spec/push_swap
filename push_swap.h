/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 21:12:52 by vkuzmina          #+#    #+#             */
/*   Updated: 2026/08/12 18:43:56 by vkuzmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

#define INT_MAX 2147483647
#define INT_MIN -2147483648

/* Stacks */

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

/* List utility functions */

t_node	*create_node(int n);
void	freedom(t_node **a);

/* Parse */

int		validation(char *str);

#endif