/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fqose <frenki.qose@learner.42.tech>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-15 20:36:00 by fqose             #+#    #+#             */
/*   Updated: 2025-12-15 20:36:00 by fqose            ###   ########.al       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	execute_move_2(t_stack **stack_a, t_stack **stack_b, t_logs *logs,
		t_element *el)
{
	while (el->rra > 0)
	{
		rrotate_a(stack_a, logs);
		el->rra--;
	}
	while (el->rb > 0)
	{
		rotate_b(stack_b, logs);
		el->rb--;
	}
	while (el->rrb > 0)
	{
		rrotate_b(stack_b, logs);
		el->rrb--;
	}
	push_a(stack_a, stack_b, logs);
}

void	execute_move(t_stack **stack_a, t_stack **stack_b, t_logs *logs,
		t_element *el)
{
	while (el->rr > 0)
	{
		rotate_r(stack_a, stack_b, logs);
		el->rr--;
	}
	while (el->rrr > 0)
	{
		rrotate_r(stack_a, stack_b, logs);
		el->rrr--;
	}
	while (el->ra > 0)
	{
		rotate_a(stack_a, logs);
		el->ra--;
	}
	execute_move_2(stack_a, stack_b, logs, el);
}

static int	find_small_index(t_stack **stack_a, int size)
{
	int		i;
	t_stack	*ptr;

	ptr = *stack_a;
	size = get_list_size(*stack_a);
	i = 0;
	while (i < size)
	{
		if (ptr->data == 0)
			return (i);
		ptr = ptr->next;
		i++;
	}
	return (0);
}

void	bring_min_to_top(t_stack **stack_a, t_logs *logs)
{
	int		size;
	int		min_index;

	if (!stack_a || !*stack_a)
		return ;
	size = get_list_size(*stack_a);
	min_index = find_small_index(stack_a, size);
	if (min_index <= size / 2)
		while (min_index-- > 0)
			rotate_a(stack_a, logs);
	else
		while (min_index++ < size)
			rrotate_a(stack_a, logs);
}

void	greedy_chunk_sort(t_stack **stack_a, t_stack **stack_b, t_logs *logs)
{
	int			size;
	int			chunk_nr;
	int			total_elements_per_chunk;	
	t_element	el_operations;

	normalize_data(stack_a);
	size = get_list_size(*stack_a);
	chunk_nr = get_sqrt(size);
	total_elements_per_chunk = (size + chunk_nr - 1) / chunk_nr;
	chunks_to_b(stack_a, stack_b, total_elements_per_chunk, logs);
	init_el_operations(&el_operations);
	while (*stack_b)
	{
		find_efficient_el(stack_a, stack_b, &el_operations);
		execute_move(stack_a, stack_b, logs, &el_operations);
	}
	bring_min_to_top(stack_a, logs);
}
