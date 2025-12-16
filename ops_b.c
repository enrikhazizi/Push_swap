/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazizi <ehazizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:49:40 by ehazizi           #+#    #+#             */
/*   Updated: 2025/12/15 15:08:47 by ehazizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_b(t_stack **stack, t_logs *logs)
{
	t_stack	*head;
	t_stack	*second;
	t_stack	*tail;
	t_stack	*third;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;

	head = *stack;
	second = head->next;
	if (second->next == head)
	{
		*stack = second;
		logs->sa++;
		logs->total++;
		log_moves(logs, "sa");
		return ;
	}
	tail = head->prev;
	third = second->next;
	tail->next = second;
	second->prev = tail;
	second->next = head;
	head->prev = second;
	third->prev = head;
	head->next = third;
	logs->sa++;
	logs->total++;
	*stack = second;
	log_moves(logs, "sb");
}

void	push_b(t_stack **stack_a, t_stack **stack_b, t_logs *logs)
{
	t_stack	*node;

	node = pop_head(stack_a);
	if (!node)
		return ;
	push_front(stack_b, node);
	logs->pa++;
	logs->total++;
	log_moves(logs, "pb");
}

void	rotate_b(t_stack **stack, t_logs *logs)
{
	*stack = (*stack)->next;
	logs->total++;
	log_moves(logs, "rb");
}

void	rrotate_b(t_stack **stack, t_logs *logs)
{
	*stack = (*stack)->prev;
	logs->total++;
	log_moves(logs, "rrb");
}
