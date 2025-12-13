/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithmic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazizi <ehazizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 17:12:59 by ehazizi           #+#    #+#             */
/*   Updated: 2025/12/10 17:34:59 by ehazizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*problem when testing with 2 elements*/
void	bubble_sort_list(t_stack **stack, t_logs *logs)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	size = get_list_size(*stack);
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if ((*stack)->data > (*stack)->next->data)
				swap_a(stack, logs);
			rotate_a(stack, logs);
			j++;
		}
		j = 0;
		while (j < size - 1 - i)
		{
			rrotate_a(stack, logs);
			j++;
		}
		i++;
	}
}

void	push_all_b(t_stack **stack_a, t_stack **stack_b, t_logs *logs)
{
	int	i;
	int	size;

	size = get_list_size(*stack_a);
	i = 0;
	while (i < size - 1)
	{
		push_b(stack_a, stack_b, logs);
		++i;
	}
}

void	insertion_sort_list(t_stack **stack_a, t_stack **stack_b, t_logs *logs)
{
	int	size_b;
	int	i;
	int	j;
	int	min_val;

	i = 0;
	push_all_b(stack_a, stack_b, logs);
	min_val = (*stack_a)->data;
	size_b = get_list_size(*stack_b);
	while (i < size_b)
	{
		if ((*stack_b)->data < min_val)
			min_val = (*stack_b)->data;
		j = 0;
		while ((*stack_b)->data > (*stack_a)->data
			&& j < get_list_size(*stack_a))
		{
			rotate_a(stack_a, logs);
			++j;
		}
		push_a(stack_a, stack_b, logs);
		while ((*stack_a)->data != min_val)
			rotate_a(stack_a, logs);
		++i;
	}
}
