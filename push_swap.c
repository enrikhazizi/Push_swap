/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazizi <ehazizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:49:55 by ehazizi           #+#    #+#             */
/*   Updated: 2025/12/10 17:30:45 by ehazizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_list(t_stack **stack, int data)
{
	t_stack	*new_node;
	t_stack	*last_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->data = data;
	if (*stack == NULL)
	{
		*stack = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
		return ;
	}
	last_node = (*stack)->prev;
	new_node->next = *stack;
	(*stack)->prev = new_node;
	new_node->prev = last_node;
	last_node->next = new_node;
}

int	parse_args(int argc, char **argv, t_stack **whole_stack, char **mode)
{
	if (argc == 2 && is_nr(argv[1]))
		return (create_from_single(argv[1], whole_stack));
	else if (argc == 3)
	{
		if (!is_nr(argv[1]))
		{
			if (!set_mode(mode, argv[1]))
				return (0);
			return (create_from_single(argv[2], whole_stack));
		}
		return (create_from_multi(argv + 1, whole_stack));
	}
	else if (argc > 3)
	{
		if (!is_nr(argv[1]))
		{
			if (!set_mode(mode, argv[1]))
				return (0);
			return (create_from_multi(argv + 2, whole_stack));
		}
		return (create_from_multi(argv + 1, whole_stack));
	}
	return (0);
}

int	choose_algorithm(char *mode, t_stack **stack_a, t_stack **stack_b,
	t_logs *logs)
{
	float	disorder;

	printf("mode: %s\n", mode); //debug
	disorder = compute_disorder(*stack_a);
	if (ft_strcmp(mode, "--simple") == 0)
		bubble_sort_list(stack_a, logs);
	else if (ft_strcmp(mode, "--medium") == 0)
		bubble_sort_list(stack_a, logs); //replace with medium algo
	else if (ft_strcmp(mode, "--complex") == 0)
		bubble_sort_list(stack_a, logs); //replace with complex algo
	else if (ft_strcmp(mode, "--adaptive") == 0)
	{
		if (disorder < 0.2)
			bubble_sort_list(stack_a, logs);
		else if (disorder < 0.5)
			bubble_sort_list(stack_a, logs); //replace with medium algo
		else
			bubble_sort_list(stack_a, logs); //replace with complex algo
	}
	else
		return (0);
	print_list(*stack_a); //debug
	return (1);
}

static int	print_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*whole_stack;
	t_stack	*whole_stack_b;
	t_logs	logs;
	char	*mode;

	if (argc == 1)
		return (0);
	init(&whole_stack, &whole_stack_b, &logs, &mode);
	if (!parse_args(argc, argv, &whole_stack, &mode))
		return (print_error());
	if (!not_has_dupes(&whole_stack))
		return (print_error());
	if (compute_disorder(whole_stack) == 0)
		return (0);
	if (!choose_algorithm(mode, &whole_stack, &whole_stack_b, &logs))
		return (print_error());
	print_moves(&logs);
	return (0);
}
