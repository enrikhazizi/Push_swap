/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazizi <ehazizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 17:14:30 by ehazizi           #+#    #+#             */
/*   Updated: 2025/12/10 17:20:45 by ehazizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_front(t_stack **stack, t_stack *node)
{
	t_stack	*head;
	t_stack	*tail;

	if (!node)
		return ;
	if (!(*stack))
	{
		node->next = node;
		node->prev = node;
		*stack = node;
		return ;
	}
	tail = head->prev;
	head = *stack;
	node->next = head;
	head->prev = node;
	node->prev = tail;
	tail->next = node;
	*stack = node;
	return ;
}

float	comput_disorader(t_stack **stack)
{
	float	mistakes;
	float	total_pairs;
	t_stack	*i;
	t_stack	*j;

	mistakes = 0;
	total_pairs = 0;
	i = (*stack);
	while (i->next != (*stack))
	{
		j = i->next;
		while (j->next != (*stack))
		{
			total_pairs++;
			if (i->data > j->data)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	return (mistakes / total_pairs);
}

int	get_max(t_stack **node)
{
	int		i;
	t_stack	*head;

	head = *node;
	i = head->data;
	head = head->next;
	while (head != *node)
	{
		if (i < head->data)
			i = head->data;
		head = head->next;
	}
	return (i);
}

int	get_list_size(t_stack *stack)
{
	int		count;
	t_stack	*cur;

	if (!stack)
		return (0);
	count = 1;
	cur = stack->next;
	while (cur != stack)
	{
		count++;
		cur = cur->next;
	}
	return (count);
}

void	free_split(char **token)
{
	int	i;

	i = 0;
	while (token[i])
	{
		free(token[i]);
		i++;
	}
	free(token);
}
