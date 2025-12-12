/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazizi <ehazizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:49:57 by ehazizi           #+#    #+#             */
/*   Updated: 2025/12/10 16:49:57 by ehazizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include "./libft/libft.h"

typedef struct s_moves
{
	char			data;
	struct moves	*next;
}	t_moves;

typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	int				data;
}	t_stack;

typedef struct s_logs
{
	t_moves	*list;
	int		pa;
	int		sa;
	int		ra;
	int		rra;
	int		sb;
	int		pb;
	int		rb;
	int		rrb;
	int		rr;
	int		rrr;
	int		total;
}	t_logs;

double	compute_disorder(t_stack *first);
void	print_list(t_stack *stack);
void	swap_a(t_stack **stack, t_logs *logs);
void	swap_b(t_stack **stack, t_logs *logs);
void	init_log(t_logs *log);
void	push_front(t_stack **stack, t_stack *node);
t_stack	*pop_head(t_stack **stack);
void	push_b(t_stack **stack_a, t_stack **stack_b, t_logs *log);
void	push_a(t_stack **stack_a, t_stack **stack_b, t_logs *log);
void	rotate_a(t_stack **stack, t_logs *logs);
void	rotate_b(t_stack **stack, t_logs *logs);
void	rrotate_b(t_stack **stack, t_logs *logs);
void	rrotate_a(t_stack **stack, t_logs *logs);
float	comput_disorader(t_stack **stack);
int		get_max(t_stack **node);
void	bubble_sort_list(t_stack **stack, t_logs *logs);
void	insertion_sort_list(t_stack **stack_a, t_stack **stack_b, t_logs *logs);
int		get_list_size(t_stack *stack);
int		is_nr(char *str);
int		set_mode(char **mode, char *str);
void	free_split(char **token);
int		create_from_single(char *str, t_stack **whole_stack);
int		create_from_multi(char **ptr, t_stack **whole_stack);
int		parse_args(int argc, char **argv, t_stack **whole_stack, char **mode);
void	create_list(t_stack **stack, int data);
void	init(t_stack **whole_stack, t_stack **whole_stack_b, t_logs *log,
			char **mode);

#endif