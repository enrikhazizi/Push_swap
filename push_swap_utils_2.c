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
	head = *stack;
	tail = head->prev;
	node->next = head;
	head->prev = node;
	node->prev = tail;
	tail->next = node;
	*stack = node;
	return ;
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

int	ft_atoi_strict(const char *str, int *out)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		num = num * 10 + (*str - '0');
		if ((num * sign) > 2147483647 || (num * sign) < -2147483648)
			return (0);
		str++;
	}
	*out = (int)(num * sign);
	return (1);
}
