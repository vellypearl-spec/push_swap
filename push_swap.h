/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 21:12:52 by vkuzmina          #+#    #+#             */
/*   Updated: 2026/08/12 16:18:04 by vkuzmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

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