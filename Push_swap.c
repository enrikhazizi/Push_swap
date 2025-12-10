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

int	main(int argc, char **argv)
{
	t_stack	*whole_stack;
	t_stack	*whole_stack_b;
	t_logs	*log;
	char	**token;
	int		i;

	if(argc == 1)
		return (0);
	i = 0;
	whole_stack_b = NULL;
	whole_stack = NULL;
	token = ft_split(argv[1]);
	if (argc == 2)
	{
		log = malloc(sizeof(t_logs));
		init_log(log);
		i = 0;
		while (token[i])
		{
			create_list(&whole_stack, ft_atoi(token[i]));
			i++;
		}
	}
	else
		printf("\n");
		
	bubble_sort_list(&whole_stack, log);
	print_list(whole_stack);
}
