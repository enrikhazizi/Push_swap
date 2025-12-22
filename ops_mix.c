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

void	sswap_2(t_stack **stack, t_logs *logs)
{
	t_stack	*head;
	t_stack	*second;
	t_stack	*tail;
	t_stack	*third;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	head = *stack;
	second = head->next;
	if (handle_two_el_b(stack, logs))
		return ;
	third = second->next;
	tail = head->prev;
	tail->next = second;
	second->prev = tail;
	head->next = third;
	third->prev = head;
	second->next = head;
	*stack = second;
	log_moves(logs, "ss");
	logs->ss++;
	logs->total++;
}

void	sswap(t_stack **stack_a, t_stack **stack_b, t_logs *logs)
{
	t_stack	*head;
	t_stack	*second;
	t_stack	*tail;
	t_stack	*third;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return ;
	head = *stack_a;
	second = head->next;
	if (handle_two_el_a(stack_a, logs))
		return ;
	third = second->next;
	tail = head->prev;
	tail->next = second;
	second->prev = tail;
	head->next = third;
	third->prev = head;
	second->next = head;
	head->prev = second;
	*stack_a = second;
	sswap_2(stack_b, logs);
}
