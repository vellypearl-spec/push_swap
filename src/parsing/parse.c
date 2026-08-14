/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 15:53:23 by vkuzmina          #+#    #+#             */
/*   Updated: 2026/08/13 18:09:35 by vkuzmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validation(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		else
			i++;
	}
	return (1);
}

long	conversion_range(char *str)
{
	long	number;
	int		i;
	long	limit;

	i = 0;
	number = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (str[0] == '-')
		limit = 2147483648;
	else 
		limit = 2147483647;
	while (str[i])
	{
		if (number > ((limit - (str[i]-'0'))/10))
			error();
		else
		{
			number = number*10 + (str[i] - '0');
			i++;
		}
	}
	number = sign(str) * number;
	return (number);
}

void	stack_builder(t_node **a, int argc, char **argv)
{
	int		i;
	long	number;
	t_node	*new;
	
	i = 1;
	while (i < argc)
	{
		if (!validation(argv[i]))
			error();
		number = conversion_range(argv[i]);
		number = (int)number;
		new = create_node(number);
		if (!new)
		{
			destroy_stack(a);
			error();
		}
		add_back(a, new);
		i++;
	}
	if (duplicate_checker(*a))
		error();
	index_stack(*a);
}

int	duplicate_checker(t_node *a)
{
	t_node	*current;
	t_node	*checker;

	current = a;
	while (current)
	{
		checker = current->next;
		while(checker)
		{
			if (checker->value == current->value)
				return(1);
			checker = checker->next;
		}
		current = current->next;
	}
	return(0);
}