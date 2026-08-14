/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 21:12:52 by vkuzmina          #+#    #+#             */
/*   Updated: 2026/08/14 15:12:13 by vkuzmina         ###   ########.fr       */
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
void	index_stack(t_node *a);
t_node	*find_last(t_node *a);
t_node	*find_before_last(t_node *a);

/* Parse */

int		validation(char *str);
long	conversion_range(char *str);
void	stack_builder(t_node **a, int argc, char **argv);
int		duplicate_checker(t_node *a);

/* Operations */
void    pb(t_node **a, t_node **b);
void    pa(t_node   **a, t_node **b);
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
void	ra(t_node **a);
void	rb(t_node **b);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);

/* Misc */
void 	error(void);
int		sign(char *str);
void	print_stack(t_node *stack);

#endif