/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_benchmark.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmina <vkuzmina@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 11:31:55 by vkuzmina          #+#    #+#             */
/*   Updated: 2026/08/18 20:53:50 by vkuzmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Strategy metric test
int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	double	disorder;

	a = NULL;
	b = NULL;
	stack_builder(&a, argc, argv);
	index_stack(a);
	disorder = calculate_disorder(a);
	g_operations = 0;
	custom_sort(&a, &b);
	printf("size: %d | disorder: %.6f | operations: %d"
		" | sorted: %s | b empty: %s\n",
		stack_size(a), disorder, g_operations,
		count_inversions(a) == 0 ? "yes" : "no",
		b == NULL ? "yes" : "no");
	destroy_stack(&a);
	destroy_stack(&b);
	return (0);
}
// Comparsion test 
/*int	main(int argc, char **argv)
{
	t_node	*a_simple;
	t_node	*b_simple;
	t_node	*a_medium;
	t_node	*b_medium;
	double	disorder;
	double	rank;

	a_simple = NULL;
	b_simple = NULL;
	a_medium = NULL;
	b_medium = NULL;

	stack_builder(&a_simple, argc, argv);
	stack_builder(&a_medium, argc, argv);

	index_stack(a_simple);
	index_stack(a_medium);

	disorder = calculate_disorder(a_simple);
	rank = rank_distance(a_simple);

	g_operations = 0;
	simple_strategy(&a_simple, &b_simple);
	printf("Simple strategy: %d operations\n", g_operations);

	g_operations = 0;
	medium_sort(&a_medium, &b_medium);
	printf("Medium sort: %d operations\n", g_operations);

	printf("Size: %d | Disorder: %.6f | Rank distance:%.6f\n", 
		argc - 1, disorder, rank);

	destroy_stack(&a_simple);
	destroy_stack(&b_simple);
	destroy_stack(&a_medium);
	destroy_stack(&b_medium);
	return (0);
}*/
// Cost prediction test
/* int	main(int argc, char **argv)
{
	t_node	*a_simple;
	t_node	*b_simple;
	int		index;
	int		predicted;
	int		before;
	int		actual;
	int		position;
	int		size;

	a_simple = NULL;
	b_simple = NULL;
	size = argc - 0;
	index = 0;
	while (size)
	{
		stack_builder(&a_simple, argc, argv);
		index_stack(a_simple);
		g_operations = 0;
		predicted = candidate_cost(a_simple, index);
		if (predicted < 0)
		{
			printf("Index: %d | Candidate unavailable\n", index);
			destroy_stack(&a_simple);
			destroy_stack(&b_simple);
			break ;
		}
		before = g_operations;
		position = find_position(a_simple, index);
		bring_to_top(&a_simple, position);
		pb(&a_simple, &b_simple);
		actual = g_operations - before;
		printf("Index: %d | Predicted: %d | Actual:%d\n", 
			index, predicted, actual);
			destroy_stack(&a_simple);
			destroy_stack(&b_simple);
		++index;
		--size;
	}
	return (0);
}*/
// Best candidate test
/*int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	int		position;

	a = NULL;
	b = NULL;
	stack_builder(&a, argc, argv);
	index_stack(a);
	g_operations = 0;
	printf("[0, 4)  Expected: 1  | Got: %d\n",
	find_best_candidate(a, 0, 4));
	printf("[2, 6)  Expected: 5  | Got: %d\n",
	find_best_candidate(a, 2, 6));
	printf("[4, 9)  Expected: 8  | Got: %d\n",
	find_best_candidate(a, 4, 9));
	printf("[1, 6)  Expected: 1  | Got: %d\n",
	find_best_candidate(a, 1, 6));
	printf("[8, 9)  Expected: 8  | Got: %d\n",
	find_best_candidate(a, 8, 9));
	printf("[9, 12) Expected: -1 | Got: %d\n",
	find_best_candidate(a, 9, 12));
	printf("[4, 4)  Expected: -1 | Got: %d\n",
	find_best_candidate(a, 4, 4));
	printf("Operations generated: %d\n", g_operations);
	
	position = find_position(a, 5);
	bring_to_top(&a, position);
	pb(&a, &b);
	position = find_position(a, 1);
	bring_to_top(&a, position);
	pb(&a, &b);
	
	printf("1 cost: %d\n", candidate_cost(a, 1));
	printf("2 cost: %d\n", candidate_cost(a, 2));
	printf("3 cost: %d\n", candidate_cost(a, 3));
	printf("4 cost: %d\n", candidate_cost(a, 4));
	printf("5 cost: %d\n", candidate_cost(a, 5));
	printf("Best [1, 6): %d\n",
		find_best_candidate(a, 1, 6));

	return (0);
}*/
// Window-cost benchmark
/* static void	test_window(t_node *a, int min, int width, int size)
{
	int	max;
	int	best;
	int	cost;

	max = min + width;
	if (max > size)
		max = size;
	best = find_best_candidate(a, min, max);
	cost = candidate_cost(a, best);
	printf("Window: %d | Range: [%d, %d) | Best: %d | Cost: %d\n",
		width, min, max, best, cost);
}
int	main(int argc, char **argv)
{
	t_node	*a;
	int		size;
	int		window;

	a = NULL;
	stack_builder(&a, argc, argv);
	index_stack(a);
	size = stack_size(a);
	g_operations = 0;
	printf("Size: %d | Disorder: %.6f | Rank distance: %.6f\n",
		size, calculate_disorder(a), rank_distance(a));
	window = 1;
	while (window < size)
	{
		test_window(a, 0, window, size);
		window *= 2;
	}
	test_window(a, 0, size, size);
	printf("Operations generated: %d\n", g_operations);
	destroy_stack(&a);
	return (0);
}*/
// Window benchmark
/*int	main(int argc, char **argv)
{
	t_node	*a;
	int		window;

	a = NULL;
	stack_builder(&a, argc, argv);
	index_stack(a);
	g_operations = 0;
	window = calculate_window(a, 0);
	printf("Size: %d | Disorder: %.6f | Rank distance: %.6f\n",
		stack_size(a), calculate_disorder(a), rank_distance(a));
	printf("Calculated window: %d\n", window);
	printf("Operations generated: %d\n", g_operations);
	destroy_stack(&a);
	return (0);
}
int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	int		index;
	int		position;
	int		window;

	a = NULL;
	b = NULL;
	stack_builder(&a, argc, argv);
	index_stack(a);
	index = 0;
	while (index < 10)
	{
		position = find_position(a, index);
		bring_to_top(&a, position);
		pb(&a, &b);
		index++;
	}
	g_operations = 0;
	window = calculate_window(a, 10);
	printf("Remaining size: %d\n", stack_size(a));
	printf("Position of min 10: %d\n", find_position(a, 10));
	printf("Largest remaining index: %d\n", find_largest_index(a));
	printf("Disorder: %.6f | Rank distance: %.6f\n",
		calculate_disorder(a), rank_distance(a));
	printf("Calculated window from min 10: %d\n", window);
	printf("Operations generated by analysis: %d\n", g_operations);
	destroy_stack(&a);
	destroy_stack(&b);
	return (0);
}*/
// Distribution+reconstruction test
/*int	main(int argc, char **argv)
{
	t_node		*a;
	t_node		*b;
	double		disorder;
	double		rank_a;
	double		rank_b;
	int			distribution_ops;
	int			reconstruction_ops;

	a = NULL;
	b = NULL;
	g_operations = 0;
	
	if (argc < 2)
		return (1);

	stack_builder(&a, argc, argv);
	index_stack(a);

	//ft_printf("Before:\n");
	//ft_printf("A: ");
	//print_stack(a);
	//ft_printf("B: ");
	//print_stack(b);

	disorder = calculate_disorder(a);
	rank_a = rank_distance(a);
	
	distribution(&a, &b);
	distribution_ops = g_operations;
	rank_b = rank_distance(b);
	
	reconstruction(&a, &b);
	reconstruction_ops = g_operations - distribution_ops;
	
	//ft_printf("\nAfter:\n");
	//ft_printf("A: ");
	//print_stack(a);
	//ft_printf("B: ");
	//print_stack(b);
	printf("size: %d | disorder: %.6f | rank A: %.6f"
		" | rank B: %.6f | sorted: %s | b empty: %s"
		" | operations: %d\n",
		stack_size(a), disorder, rank_a, rank_b,
		count_inversions(a) == 0 ? "yes" : "no",
		b == NULL ? "yes" : "no", g_operations);
	printf("distribution: %d | reconstruction: %d | total: %d\n",
	distribution_ops, reconstruction_ops, g_operations);
	
	destroy_stack(&a);
	destroy_stack(&b);
	return (0);
}*/
// Itsy bitsy tiny test
/*int	main(void)
{
	t_node	*b;
	t_node	*tmp;
	t_node	*new;
	
	b = NULL;
	
	new = create_node(10);
	new->index = 10;
	add_back(&b, new);
	new = create_node(8);
	new->index = 8;
	add_back(&b, new);
	new = create_node(6);
	new->index = 6;
	add_back(&b, new);
	new = create_node(4);
	new->index = 4;
	add_back(&b, new);
	
	tmp = b;
	while (tmp)
	{
		printf("value: %d | index: %d\n", tmp->value, tmp->index);
		tmp = tmp->next;
	}
	printf("target 7  -> %d\n", find_b_insert_position(b, 7));
	printf("target 9  -> %d\n", find_b_insert_position(b, 9));
	printf("target 12 -> %d\n", find_b_insert_position(b, 12));
	printf("target 2  -> %d\n", find_b_insert_position(b, 2));
	
	destroy_stack(&b);
	b = NULL;
	new = create_node(6);
	new->index = 6;
	add_back(&b, new);
	new = create_node(4);
	new->index = 4;
	add_back(&b, new);
	new = create_node(10);
	new->index = 10;
	add_back(&b, new);
	new = create_node(8);
	new->index = 8;
	add_back(&b, new);
	tmp = b;
	while (tmp)
	{
		printf("index: %d ", tmp->index);
		tmp = tmp->next;
	}
	printf("\n");
	printf("rotated target 7 -> %d\n",
		find_b_insert_position(b, 7));
	destroy_stack(&b);
	b = NULL;
	new = create_node(4);
	new->index = 4;
	add_back(&b, new);
	new = create_node(10);
	new->index = 10;
	add_back(&b, new);
	new = create_node(6);
	new->index = 6;
	add_back(&b, new);
	new = create_node(3);
	new->index = 3;
	add_back(&b, new);
	new = create_node(9);
	new->index = 9;
	add_back(&b, new);
	new = create_node(5);
	new->index = 5;
	add_back(&b, new);
	new = create_node(8);
	new->index = 8;
	add_back(&b, new);
	new = create_node(2);
	new->index = 2;
	add_back(&b, new);
	tmp = b;
	while (tmp)
	{
		printf("index: %d ", tmp->index);
		tmp = tmp->next;
	}
	printf("\n");
	printf("rotated target 7 -> %d\n",
		find_b_insert_position(b, 7));
	destroy_stack(&b);
	return (0);
}*/
// Hitchhike test
/*int	main(void)
{
	t_node	*a;
	t_node	*b;
	int		i;

	a = NULL;
	b = NULL;
	i = 0;
	while (i < 10)
	{
		add_back(&a, create_node(i));
		add_back(&b, create_node(i));
		i++;
	}
	printf("4 / 2 -> %d (expected 4)\n",
		hitchike(a, b, 4, 2));
	printf("7 / 8 -> %d (expected 3)\n",
		hitchike(a, b, 7, 8));
	printf("4 / 8 -> %d (expected 6)\n",
		hitchike(a, b, 4, 8));
	printf("2 / 4 -> %d (expected 4)\n",
		hitchike(a, b, 2, 4));
	printf("5 / 3 -> %d (expected 5)\n",
		hitchike(a, b, 5, 3));
	printf("0 / 3 -> %d (expected 3)\n",
		hitchike(a, b, 0, 3));
	printf("0 / 0 -> %d (expected 0)\n",
		hitchike(a, b, 0, 0));
	printf("8 / 7 -> %d (expected 3)\n",
		hitchike(a, b, 8, 7));
	destroy_stack(&a);
	destroy_stack(&b);
return (0);
}*/
// Executor test
/*int	main(void)
{
	t_node	*a;
	t_node	*b;
	int		i;

	a = NULL;
	b = NULL;
	i = 0;
	while (i < 10)
	{
		add_back(&a, create_node(i));
		add_back(&b, create_node(i));
		i++;
	}
	g_operations = 0;
	execute_hitchike(&a, &b, 7, 8);
	printf("operations: %d\n", g_operations);
	print_stack(a);
	print_stack(b);
	destroy_stack(&a);
	destroy_stack(&b);
	return (0);
}*/