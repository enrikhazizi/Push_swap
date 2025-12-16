/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fqose <fqose@student.42.fr>                #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-15 20:36:00 by fqose             #+#    #+#             */
/*   Updated: 2025-12-15 20:36:00 by fqose            ###   ########.al       */
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

int	find_min_index(t_stack **stack_a, int size)
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

void	calc_strategy(t_element *el)
{
	int	rr;
	int	rrr;
	int	cost_rr;
	int	cost_rrr;
	int	cost_ra_rrb;
	int	cost_rra_rb;

	rr = min(el->ra, el->rb);
	rrr = min(el->rra, el->rrb);
	cost_rr = max(el->ra, el->rb);
	cost_rrr = max(el->rra, el->rrb);
	cost_ra_rrb = el->ra + el->rrb;
	cost_rra_rb = el->rra + el->rb;
	el->strategy = RR;
	el->total = cost_rr;
	if (cost_rrr < el->total)
	{
		el->strategy = RRR;
		el->total = cost_rrr;
	}
	if (cost_ra_rrb < el->total)
	{
		el->strategy = RA_RRB;
		el->total = cost_ra_rrb;
	}
	if (cost_rra_rb < el->total)
	{
		el->strategy = RRA_RB;
		el->total = cost_rra_rb;
	}
	el->rr = 0;
	el->rrr = 0;
	if (el->strategy == RR)
	{
		el->rr = rr;
		el->ra -= rr;
		el->rb -= rr;
		el->rra = 0;
		el->rrb = 0;
	}
	else if (el->strategy == RRR)
	{
		el->rrr = rrr;
		el->rra -= rrr;
		el->rrb -= rrr;
		el->ra = 0;
		el->rb = 0;
	}
	else if (el->strategy == RA_RRB)
	{
		el->rra = 0;
		el->rb = 0;
	}
	else if (el->strategy == RRA_RB)
	{
		el->ra = 0;
		el->rrb = 0;
	}
}

void	find_efficient_el(t_stack **stack_a, t_stack **stack_b,
							t_element *best)
{
	int			size_a;
	int			size_b;
	int			i;
	t_stack		*cur_b;
	t_element	tmp;

	if (!stack_b || !*stack_b)
		return;
	size_b = get_list_size(*stack_b);
	size_a = get_list_size(*stack_a);
	if (size_b == 0)
		return ;
	cur_b = *stack_b;
	best->total = 2147483647;
	i = 0;
	while (i < size_b)
	{
		tmp.element = cur_b;
		tmp.ra = find_place_a(stack_a, cur_b, size_a);
		tmp.rra = size_a - tmp.ra;
		tmp.rb = i;
		tmp.rrb = size_b - i;
		calc_strategy(&tmp);
		if (tmp.total < best->total)
			*best = tmp;

		cur_b = cur_b->next;
		i++;
	}
}

void	execute_move(t_stack **stack_a, t_stack **stack_b, t_logs *logs, t_element *el)
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

void	bring_min_to_top(t_stack **stack_a, t_logs *logs)
{
	int		size;
	int		min_index;
	int		i;
	t_stack	*ptr;

	if (!stack_a || !*stack_a)
		return ;
	size = get_list_size(*stack_a);
	ptr = *stack_a;
	min_index = 0;
	i = 0;
	while (i < size)
	{
		if (ptr->data == 0)
		{
			min_index = i;
			break ;
		}
		ptr = ptr->next;
		i++;
	}
	if (min_index <= size / 2)
		while (min_index-- > 0)
			rotate_a(stack_a, logs);
	else
		while (min_index++ < size)
			rrotate_a(stack_a, logs);
}

void    greedy_chunk_sort(t_stack **stack_a, t_stack **stack_b, t_logs *logs)
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
