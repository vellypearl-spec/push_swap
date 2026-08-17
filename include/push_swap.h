/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 21:12:52 by vkuzmina          #+#    #+#             */
/*   Updated: 2026/08/17 16:29:59 by vkuzmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

int	g_operations;

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
int		find_position(t_node *a, int target_index);
int		stack_size(t_node *a);
void	bring_to_top(t_node **a, int position);

/* Parse */

int		validation(char *str);
long	conversion_range(char *str);
void	stack_builder(t_node **a, int argc, char **argv);
int		duplicate_checker(t_node *a);

/* Operations */
void	pb(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
void	ra(t_node **a);
void	rb(t_node **b);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);

/* Operation cost */
int		rotation_cost(int size, int position);

/* Disorder metric */
int		count_inversions(t_node *a);
double	calculate_disorder(t_node *a);

/* Simple startegy */
void	simple_strategy(t_node **a, t_node **b);

/* Medium sort */
void	medium_sort(t_node **a, t_node **b);
void	bring_to_top_b(t_node **b, int position);

/* Small sorting */
void	sort_two(t_node **a);
void	sort_three(t_node **a);
void	sort_five(t_node **a, t_node **b);

/* Misc */

void	error(void);
int		sign(char *str);
void	print_stack(t_node *stack);

#endif