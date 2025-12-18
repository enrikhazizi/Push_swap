/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fqose <frenki.qose@learner.42.tech>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-16 22:34:00 by fqose             #+#    #+#             */
/*   Updated: 2025-12-16 22:34:00 by fqose            ###   ########.al       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	init_el_operations(t_element *el_operations)
{
	el_operations->ra = 0;
	el_operations->rb = 0;
	el_operations->rra = 0;
	el_operations->rrb = 0;
	el_operations->total = 0;
}

static int	find_min_index(t_stack **stack_a, int size)
{
	t_stack	*ptr;
	int		min;
	int		index;
	int		i;

	if (!stack_a || !*stack_a || size == 0)
		return (0);
	ptr = *stack_a;
	min = ptr->data;
	index = 0;
	i = 0;
	while (i < size)
	{
		if (ptr->data < min)
		{
			min = ptr->data;
			index = i;
		}
		ptr = ptr->next;
		++i;
	}
	return (index);
}

int	find_place_a(t_stack **stack_a, t_stack *el, int size)
{
	t_stack	*ptr;
	int		i;

	if (!stack_a || !*stack_a || size == 0)
		return (0);
	ptr = *stack_a;
	i = 0;
	while (i < size)
	{
		if ((ptr->data < ptr->next->data
				&& el->data > ptr->data
				&& el->data < ptr->next->data)
			|| (ptr->data > ptr->next->data
				&& (el->data > ptr->data
					|| el->data < ptr->next->data)))
			return (i + 1);
		ptr = ptr->next;
		++i;
	}
	return (find_min_index(stack_a, size));
}
