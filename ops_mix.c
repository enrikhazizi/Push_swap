/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_mix.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazizi <ehazizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:49:49 by ehazizi           #+#    #+#             */
/*   Updated: 2025/12/10 17:05:13 by ehazizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_r(t_stack **stack_a, t_stack **stack_b, t_logs *logs)
{
	*stack_a = (*stack_a)->next;
	*stack_b = (*stack_b)->next;
	logs->rr++;
	logs->total++;
	log_moves(logs, "rr");
}

void	rrotate_r(t_stack **stack_a, t_stack **stack_b, t_logs *logs)
{
	*stack_a = (*stack_a)->prev;
	*stack_b = (*stack_b)->prev;
	logs->rrr++;
	logs->total++;
	log_moves(logs, "rrr");
}
