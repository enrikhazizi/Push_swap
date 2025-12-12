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

void	init(t_stack **whole_stack, t_stack **whole_stack_b, t_logs *log,
		char **mode)
{
	init_log(log);
	*whole_stack_b = NULL;
	*whole_stack = NULL;
	*mode = "--adaptive";
}

int	main(int argc, char **argv)
{
	t_stack	*whole_stack;
	t_stack	*whole_stack_b;
	t_logs	log;
	char	*mode;

	if (argc == 1)
	{
		printf("Invalid arguments"); /*debugging*/
		return (1);
	}
	init(&whole_stack, &whole_stack_b, &log, &mode);
	if (!parse_args(argc, argv, &whole_stack, &mode))
	{
		printf("Invalid arguments"); /*debugging*/
		return (1);
	}
	/*debugging and testing*/
	printf("%s\n", mode);
	printf("disorder before : %f\n", comput_disorader(&whole_stack));
	bubble_sort_list(&whole_stack, &log);
	print_list(whole_stack);
	printf("disorder after : %f\n", comput_disorader(&whole_stack));
	return (0);
}
