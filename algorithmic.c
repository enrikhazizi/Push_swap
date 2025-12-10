/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithmic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazizi <ehazizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 17:12:59 by ehazizi           #+#    #+#             */
/*   Updated: 2025/12/10 17:34:59 by ehazizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort_list(t_stack **stack, t_logs *logs)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	size = get_list_size(*stack);
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if ((*stack)->data > (*stack)->next->data)
				swap_a(stack, logs);
			rotate_a(stack, logs);
			j++;
		}
		j = 0;
		while (j < size - 1 - i)
		{
			rrotate_a(stack, logs);
			j++;
		}
		i++;
	}
}
