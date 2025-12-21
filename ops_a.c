/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazizi <ehazizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:49:45 by ehazizi           #+#    #+#             */
/*   Updated: 2025/12/15 15:08:41 by ehazizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	handle_two_el_a(t_stack **stack, t_logs *logs)
{
	t_stack	*head;
	t_stack	*second;

	head = *stack;
	second = head->next;
	if (second->next == head)
	{
		*stack = second;
		logs->sa++;
		logs->total++;
		log_moves(logs, "sa");
		return (1);
	}
	return (0);
}

void	swap_a(t_stack **stack, t_logs *logs)
{
	t_stack	*head;
	t_stack	*second;
	t_stack	*tail;
	t_stack	*third;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	head = *stack;
	second = head->next;
	if (handle_two_el_a(stack, logs))
		return ;
	third = second->next;
	tail = head->prev;
	tail->next = second;
	second->prev = tail;
	head->next = third;
	third->prev = head;
	second->next = head;
	head->prev = second;
	logs->sa++;
	logs->total++;
	*stack = second;
	log_moves(logs, "sa");
}

void	push_a(t_stack **stack_a, t_stack **stack_b, t_logs *log)
{
	t_stack	*node;

	node = pop_head(stack_b);
	if (!node)
		return ;
	push_front(stack_a, node);
	log->pa++;
	log->total++;
	log_moves(log, "pa");
}

void	rotate_a(t_stack **stack, t_logs *logs)
{
	*stack = (*stack)->next;
	logs->ra++;
	logs->total++;
	log_moves(logs, "ra");
}

void	rrotate_a(t_stack **stack, t_logs *logs)
{
	*stack = (*stack)->prev;
	logs->rra++;
	logs->total++;
	log_moves(logs, "rra");
}
