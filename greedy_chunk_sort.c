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

//TODO: test functions one by one
void	init_el_operations(t_element *el_operations){
	el_operations->ra = 0;
	el_operations->rb = 0;
	el_operations->rra = 0;
	el_operations->rrb = 0;
	el_operations->total = 0;
}

int	find_place_a(t_stack **stack_a, t_stack *el, int size)
{
	t_stack	*ptr;
	int		i;

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
	return (0);
}

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

void	calc_strategy(t_element *el)
{
	int	total_rr;
	int	total_rrr;
	int	total_ra_rrb;
	int	total_rra_rb;

	// Initialize shared rotations
	el->rr = 0;
	el->rrr = 0;

	// 1️⃣ Compute total moves for each strategy without ternary
	if (el->ra > el->rb)
		total_rr = el->ra;
	else
		total_rr = el->rb;

	if (el->rra > el->rrb)
		total_rrr = el->rra;
	else
		total_rrr = el->rrb;

	total_ra_rrb = el->ra + el->rrb;
	total_rra_rb = el->rra + el->rb;

	// 2️⃣ Initialize with FF (rr) as default
	el->total = total_rr;
	el->strategy = FF;

	// 3️⃣ Compare and update strategy
	if (total_rrr < el->total)
	{
		el->total = total_rrr;
		el->strategy = BB;
	}
	if (total_ra_rrb < el->total)
	{
		el->total = total_ra_rrb;
		el->strategy = FB;
	}
	if (total_rra_rb < el->total)
	{
		el->total = total_rra_rb;
		el->strategy = BF;
	}

	// 4️⃣ Adjust rotation counts for combined strategies
	if (el->strategy == FF)
	{
		if (el->ra > el->rb)
		{
			el->rr = el->rb;
			el->ra -= el->rb;
			el->rb = 0;
		}
		else
		{
			el->rr = el->ra;
			el->rb -= el->ra;
			el->ra = 0;
		}
	}
	else if (el->strategy == BB)
	{
		if (el->rra > el->rrb)
		{
			el->rrr = el->rrb;
			el->rra -= el->rrb;
			el->rrb = 0;
		}
		else
		{
			el->rrr = el->rra;
			el->rrb -= el->rra;
			el->rra = 0;
		}
	}
	// FB and BF stay unchanged
}


void	find_efficient_el(t_stack **stack_a, t_stack **stack_b,
							t_logs *logs, t_element *el_operations)
{
	int			size_a;
	int			size_b;
	int			i;
	t_stack		*cur_b;
	t_element	tmp;

	size_b = get_list_size(*stack_b);
	size_a = get_list_size(*stack_a);
	cur_b = *stack_b;

	// Initialize with first element
	tmp.element = cur_b;
	tmp.ra = find_place_a(stack_a, cur_b, size_a);
	tmp.rra = size_a - tmp.ra;
	tmp.rb = 0;
	tmp.rrb = size_b;
	calc_strategy(&tmp);
	*el_operations = tmp;

	i = 1;
	cur_b = cur_b->next;
	while (i < size_b)
	{
		tmp.element = cur_b;
		tmp.ra = find_place_a(stack_a, cur_b, size_a);
		tmp.rra = size_a - tmp.ra;
		tmp.rb = i;
		tmp.rrb = size_b - i;

		calc_strategy(&tmp);

		if (tmp.total < el_operations->total)
			*el_operations = tmp;

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

void    greedy_chunk_sort(t_stack **stack_a, t_stack **stack_b, t_logs *logs)
{
	int			size;
	int			chunk_nr;
	int			total_elements_per_chunk;	
	int			i;
    t_element	el_operations;

	normalize_data(stack_a);
	size = get_list_size(*stack_a);
	chunk_nr = get_sqrt(size);
	total_elements_per_chunk = (size + chunk_nr - 1) / chunk_nr;
	chunks_to_b(stack_a, stack_b, total_elements_per_chunk, logs);

	init_el_operations(&el_operations);
	while (*stack_b)
	{
		find_efficient_el(stack_a, stack_b, logs, &el_operations);
		execute_move(stack_a, stack_b, logs, &el_operations);
	}
	print_list(*stack_a);
}
