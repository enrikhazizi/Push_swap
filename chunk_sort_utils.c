/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fqose <fqose@student.42.fr>                #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-14 16:11:33 by fqose             #+#    #+#             */
/*   Updated: 2025-12-14 16:11:33 by fqose            ###   ########.al       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_sqrt(double x)
{
	double	guess;
	double	epsilon;
	int		root_int;

	if (x < 0)
		return (-1);
	if (x == 0)
		return (0);
	guess = x / 2.0;
	epsilon = 1e-6;
	while ((guess * guess - x) > epsilon || (guess * guess - x) < -epsilon)
		guess = (guess + x / guess) / 2.0;
	root_int = (int)guess;
	if (root_int * root_int < x)
		root_int++;
	return (root_int);
}

void	bubble_sort_array(int *data, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (data[j] < data[i])
			{
				tmp = data[i];
				data[i] = data[j];
				data[j] = tmp;
			}
			++j;
		}
		++i;
	}
}

void	index_data(t_stack **stack_a, int *data, int size)
{
	int		i;
	int		j;
	t_stack	*ptr;

	i = 0;
	ptr = *stack_a;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (ptr->data == data[j])
			{
				ptr->data = j;
				break ;
			}
			++j;
		}
		++i;
		ptr = ptr->next;
	}
}

void	normalize_data(t_stack **stack_a)
{
	int		*data;
	int		size;
	int		i;
	t_stack	*ptr;

	i = 0;
	ptr = *stack_a;
	size = get_list_size(*stack_a);
	data = malloc(sizeof(int) * size);
	if (!data)
		return ;
	while (i < size)
	{
		data[i] = ptr->data;
		ptr = ptr->next;
		++i;
	}
	bubble_sort_array(data, size);
	index_data(stack_a, data, size);
	free(data);
}
