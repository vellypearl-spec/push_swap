/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 21:12:52 by vkuzmina          #+#    #+#             */
/*   Updated: 2026/08/13 14:19:51 by vkuzmina         ###   ########.fr       */
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
void	destroy_stack(t_node **a);
void	add_back(t_node **a, t_node *new);

/* Parse */

int		validation(char *str);
long	conversion_range(char *str);
void	stack_builder(t_node **a, int argc, char **argv);


/* Misc */
void 	error(void);
int		sign(char *str);

#endif