/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fqose <fqose@student.42.fr>                #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-16 22:34:00 by fqose             #+#    #+#             */
/*   Updated: 2025-12-16 22:34:00 by fqose            ###   ########.al       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	calc_strategy_part1(t_element *el, int *rr, int *rrr,
		t_costs *costs)
{
	*rr = min(el->ra, el->rb);
	*rrr = min(el->rra, el->rrb);
	costs->cost_rr = max(el->ra, el->rb);
	costs->cost_rrr = max(el->rra, el->rrb);
	costs->cost_ra_rrb = el->ra + el->rrb;
	costs->cost_rra_rb = el->rra + el->rb;
	el->strategy = RR;
	el->total = costs->cost_rr;
	if (costs->cost_rrr < el->total)
	{
		el->strategy = RRR;
		el->total = costs->cost_rrr;
	}
	if (costs->cost_ra_rrb < el->total)
	{
		el->strategy = RA_RRB;
		el->total = costs->cost_ra_rrb;
	}
	if (costs->cost_rra_rb < el->total)
	{
		el->strategy = RRA_RB;
		el->total = costs->cost_rra_rb;
	}
}

static void	calc_strategy_part2(t_element *el, int *rr, int *rrr)
{
	el->rr = 0;
	el->rrr = 0;
	if (el->strategy == RR)
	{
		el->rr = *rr;
		el->ra -= *rr;
		el->rb -= *rr;
		el->rra = 0;
		el->rrb = 0;
	}
	else if (el->strategy == RRR)
	{
		el->rrr = *rrr;
		el->rra -= *rrr;
		el->rrb -= *rrr;
		el->ra = 0;
		el->rb = 0;
	}
}

static void	calc_strategy_part3(t_element *el)
{
	if (el->strategy == RA_RRB)
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

static void	calc_strategy(t_element *el)
{
	int		rr;
	int		rrr;
	t_costs	costs;

	calc_strategy_part1(el, &rr, &rrr, &costs);
	calc_strategy_part2(el, &rr, &rrr);
	calc_strategy_part3(el);
}

void	find_efficient_el(t_stack **stack_a, t_stack **stack_b,
							t_element *best)
{
	t_find_vars	v;

	if (!stack_b || !*stack_b)
		return ;
	v.size_b = get_list_size(*stack_b);
	v.size_a = get_list_size(*stack_a);
	if (v.size_b == 0)
		return ;
	v.cur_b = *stack_b;
	best->total = 2147483647;
	v.i = 0;
	while (v.i < v.size_b)
	{
		v.tmp.element = v.cur_b;
		v.tmp.ra = find_place_a(stack_a, v.cur_b, v.size_a);
		v.tmp.rra = v.size_a - v.tmp.ra;
		v.tmp.rb = v.i;
		v.tmp.rrb = v.size_b - v.i;
		calc_strategy(&v.tmp);
		if (v.tmp.total < best->total)
			*best = v.tmp;
		v.cur_b = v.cur_b->next;
		v.i++;
	}
}
