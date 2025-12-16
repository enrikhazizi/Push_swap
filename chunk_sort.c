/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fqose <fqose@student.42.fr>                #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-13 10:10:22 by fqose             #+#    #+#             */
/*   Updated: 2025-12-13 10:10:22 by fqose            ###   ########.al       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunks_to_b(t_stack **stack_a, t_stack **stack_b,
						int elements_per_chunk, t_logs *logs)
{
	int	bottom;
	int	i;
	int	size_a;

	bottom = 0;
	while (*stack_a)
	{
		i = 0;
		size_a = get_list_size(*stack_a);
		while (i < size_a)
		{
			if ((*stack_a)->data >= bottom
				&& (*stack_a)->data < bottom + elements_per_chunk)
				push_b(stack_a, stack_b, logs);
			else
				rotate_a(stack_a, logs);
			i++;
		}
		bottom += elements_per_chunk;
	}
}

static void	find_and_push(int index, t_stack **b, t_stack **a, t_logs *logs)
{
	int	size;

	size = get_list_size(*b);
	if (index <= size / 2)
	{
		while (index-- > 0)
			rotate_b(b, logs);
	}
	else
	{
		index = size - index;
		while (index-- > 0)
			rrotate_b(b, logs);
	}
	push_a(a, b, logs);
}

static int	search_index(t_stack **stack_b, int target)
{
	t_stack	*ptr;
	int		i;
	int		size;

	size = get_list_size(*stack_b);
	i = 0;
	ptr = *stack_b;
	while (i < size)
	{
		if (ptr->data == target)
			return (i);
		ptr = ptr->next;
		i++;
	}
	return (-1);
}

void	chunk_sort_list(t_stack **stack_a, t_stack **stack_b, t_logs *logs)
{
	int	size;
	int	chunk_nr;
	int	total_elements_per_chunk;
	int	i;

	normalize_data(stack_a);
	size = get_list_size(*stack_a);
	chunk_nr = get_sqrt(size);
	total_elements_per_chunk = (size + chunk_nr - 1) / chunk_nr;
	chunks_to_b(stack_a, stack_b, total_elements_per_chunk, logs);
	while (*stack_b)
	{
		size = get_list_size(*stack_b);
		i = search_index(stack_b, size - 1);
		find_and_push(i, stack_b, stack_a, logs);
	}
}
