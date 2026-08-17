# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    medium_sort_test.c                                 :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glouis <glouis@student.42wolfsburg.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/17 14:22:38 by glouis            #+#    #+#              #
#    Updated: 2026/08/17 14:22:38 by glouis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

/* name=medium_sort_test.c */
#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
	int             value;
	int             index;
	struct s_node   *next;
}   t_node;

int size(t_node *a)
{
	int n = 0;
	while (a)
	{
		n++;
		a = a->next;
	}
	return (n);
}

void pb(t_node **a, t_node **b)
{
	t_node *tmp;
	if (!*a)
		return;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
}

void pa(t_node **a, t_node **b)
{
	t_node *tmp;
	if (!*b)
		return;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
}

void ra(t_node **a)
{
	t_node *first;
	t_node *tmp;
	if (!*a || !(*a)->next)
		return;
	first = *a;
	*a = (*a)->next;
	tmp = *a;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = first;
	first->next = NULL;
}

void rb(t_node **b)
{
	ra(b);
}

/* compute chunk threshold (ceil(sqrt(n))) */
int get_chunk_size(int n)
{
	int size = 1;
	while (size * size < n)
		size++;
	return (size);
}

static void fill_chunk(t_node **a, t_node **b, int min, int max)
{
	int len = size(*a);
	int i = 0;
	while (i < len)
	{
		if ((*a)->index >= min && (*a)->index < max)
			pb(a, b);
		else
			ra(a);
		i++;
	}
}

/* Insert back from B to A by selecting the node with the largest index */
static void insert_chunk_descending(t_node **a, t_node **b)
{
	int best_idx;
	int len;
	int i;

	while (*b)
	{
		best_idx = (*b)->index;
		len = size(*b);
		i = 0;
		/* find largest index in b (rotating forward while scanning) */
		while (i < len)
		{
			if ((*b)->index > best_idx)
				best_idx = (*b)->index;
			rb(b);
			i++;
		}
		/* rotate until the node with largest index is on top */
		while ((*b)->index != best_idx)
			rb(b);
		pa(a, b);
	}
}

void medium_sort(t_node **a, t_node **b)
{
	int n = size(*a);
	int chunk_size = get_chunk_size(n);
	int num_chunks = (n + chunk_size - 1) / chunk_size;
	int chunk = num_chunks - 1;
	int min, max;

	while (chunk >= 0)
	{
		min = chunk * chunk_size;
		max = min + chunk_size;
		if (max > n)
			max = n;
		fill_chunk(a, b, min, max);
		insert_chunk_descending(a, b);
		chunk--;
	}
}

void print_stack(t_node *a)
{
	while (a)
	{
		printf("%d ", a->value);
		a = a->next;
	}
	printf("\n");
}

int main(void)
{
	int values[] = {8, 3, 1, 9, 2, 7, 4, 6, 5, 0};
	int n = 10;
	t_node *a = NULL, *b = NULL, *tmp, *last;

	for (int i = 0; i < n; i++)
	{
		tmp = malloc(sizeof(t_node));
		if (!tmp)
		{
			perror("malloc");
			return 1;
		}
		tmp->value = values[i];
		/* For this test we set index = rank (0..n-1). Here values already 0..9 */
		tmp->index = values[i];
		tmp->next = NULL;
		if (!a)
			a = tmp;
		else
		{
			last = a;
			while (last->next)
				last = last->next;
			last->next = tmp;
		}
	}
	printf("before: ");
	print_stack(a);
	medium_sort(&a, &b);
	printf("after:  ");
	print_stack(a);
	printf("b empty? %s\n", b == NULL ? "yes" : "NO - bug!");
	/* free list (not strictly needed in short-lived test) */
	while (a)
	{
		tmp = a->next;
		free(a);
		a = tmp;
	}
	return 0;
}
