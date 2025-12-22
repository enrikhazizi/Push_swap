/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazizi <ehazizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 07:39:16 by fqose             #+#    #+#             */
/*   Updated: 2025/12/15 14:20:20 by ehazizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init(t_stacks *stacks, t_logs *logs,
		char **mode)
{
	init_log(logs);
	stacks->stack_a = NULL;
	stacks->stack_b = NULL;
	*mode = "--adaptive";
}

int	not_has_dupes(t_stack **stack_a)
{
	int		i;
	int		j;
	t_stack	*ptr;
	t_stack	*head;

	i = 0;
	head = *stack_a;
	if (get_list_size(*stack_a) == 1)
		return (1);
	while (i < get_list_size(*stack_a))
	{
		j = i + 1;
		ptr = head->next;
		while (j < get_list_size(*stack_a))
		{
			if (ptr->data == head->data)
				return (0);
			ptr = ptr->next;
			++j;
		}
		head = head->next;
		++i;
	}
	return (1);
}

t_moves	*new_move(char *data)
{
	t_moves	*node;

	node = malloc(sizeof(t_moves));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}

void	log_moves(t_logs *log, char *data)
{
	t_moves	*tmp;
	t_moves	*new;

	new = new_move(data);
	if (!new)
		return ;
	if (!log->list)
		log->list = new;
	else
	{
		tmp = log->list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	print_moves(t_logs *logs)
{
	while (logs->list)
	{
		ft_printf(1, "%s\n", logs->list->data);
		logs->list = logs->list->next;
	}
}
