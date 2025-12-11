/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazizi <ehazizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:49:52 by ehazizi           #+#    #+#             */
/*   Updated: 2025/12/10 17:18:58 by ehazizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_stack *stack)
{
	t_stack	*cur;

	if (!stack)
		return ;
	printf("List forward: \n");
	printf("%d\n", stack->data);
	cur = stack->next;
	while (cur != stack)
	{
		printf("%d\n", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void	init_log(t_logs *log)
{
	log->pa = 0;
	log->sa = 0;
	log->ra = 0;
	log->rra = 0;
	log->pb = 0;
	log->sb = 0;
	log->rb = 0;
	log->rrb = 0;
	log->rr = 0;
	log->rrr = 0;
	log->total = 0;
	log->list = NULL;
}

t_stack	*pop_head(t_stack **stack)
{
	t_stack	*new_head;
	t_stack	*tail;
	t_stack	*head;

	if (!stack || !(*stack))
		return (NULL);
	head = *stack;
	if (head->next == head)
	{
		*stack = NULL;
		return (head);
	}
	new_head = head->next;
	tail = head->prev;
	tail->next = new_head;
	new_head->prev = tail;
	*stack = new_head;
	return (head);
}
