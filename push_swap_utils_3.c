/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fqose <fqose@student.42.fr>                #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-13 07:39:16 by fqose             #+#    #+#             */
/*   Updated: 2025-12-13 07:39:16 by fqose            ###   ########.al       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init(t_stack **whole_stack, t_stack **whole_stack_b, t_logs *logs,
		char **mode)
{
	init_log(logs);
	*whole_stack_b = NULL;
	*whole_stack = NULL;
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
