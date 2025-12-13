/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fqose <fqose@student.42.fr>                #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-13 10:10:22 by fqose             #+#    #+#             */
/*   Updated: 2025-12-13 10:10:22 by fqose            ###   ########.fr       */
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
	int 	*data;
	int 	size;
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

static void	chunks_to_b(t_stack **stack_a, t_stack **stack_b,
						int elements_per_chunk, t_logs *logs)
{
	int	bottom;
	int	i;
	int	size_a;

	bottom = 0;
	while (*stack_a)
	{
		i = 0;
		size_a = get_list_size(*stack_a);
		while (i < size_a)
		{
			if ((*stack_a)->data >= bottom
				&& (*stack_a)->data < bottom + elements_per_chunk)
				push_b(stack_a, stack_b, logs);
			else
				rotate_a(stack_a, logs);
			i++;
		}
		bottom += elements_per_chunk;
	}
}

void	chunk_sort_list(t_stack **stack_a, t_stack **stack_b, t_logs *logs)
{
	int	size;
	int	chunk_nr;
	int	elements_per_chunk;
	int	bottom;
	int	i;
	t_stack	*ptr;

	normalize_data(stack_a);
	size = get_list_size(*stack_a);
	chunk_nr = get_sqrt(size);
	elements_per_chunk = (size + chunk_nr - 1) / chunk_nr;
	chunks_to_b(stack_a, stack_b, elements_per_chunk, logs);
	print_list(*stack_b);
}
