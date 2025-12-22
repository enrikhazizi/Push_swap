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

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include "./libft/ft_printf.h"

typedef struct s_moves
{
	char			*data;
	struct s_moves	*next;
}	t_moves;

typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	int				data;
}	t_stack;

typedef struct s_stacks
{
	t_stack	*stack_a;
	t_stack	*stack_b;
}	t_stacks;

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
	int		ss;
	int		total;
}	t_logs;

typedef enum e_strategy
{
	RR,
	RRR,
	RRA_RB,
	RA_RRB
}	t_strategy;

typedef struct s_element
{
	t_stack		*element;
	int			ra;
	int			rra;
	int			rb;
	int			rrb;
	int			rr;
	int			rrr;
	int			total;
	t_strategy	strategy;
}	t_element;

typedef struct s_costs
{
	int	cost_rr;
	int	cost_rrr;
	int	cost_ra_rrb;
	int	cost_rra_rb;
}	t_costs;

typedef struct s_find_vars
{
	int			size_a;
	int			size_b;
	int			i;
	t_stack		*cur_b;
	t_element	tmp;
}	t_find_vars;

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
int		choose_algorithm(char *mode, t_stack **stack_a, t_stack **stack_b,
			t_logs *logs);
int		ft_strcmp(char *s1, char *s2);
int		ft_atoi_strict(const char *str, int *out);
int		not_has_dupes(t_stack **stack_a);
void	init(t_stacks *stacks, t_logs *logs,
			char **mode);
void	chunk_sort_list(t_stack **stack_a, t_stack **stack_b, t_logs *logs);
t_moves	*new_move(char *data);
void	print_moves(t_logs *logs);
void	log_moves(t_logs *log, char *data);
int		get_sqrt(double x);
void	bubble_sort_array(int *data, int size);
void	index_data(t_stack **stack_a, int *data, int size);
void	normalize_data(t_stack **stack_a);
void	greedy_chunk_sort(t_stack **stack_a, t_stack **stack_b, t_logs *logs);
void	rotate_r(t_stack **stack_a, t_stack **stack_b, t_logs *logs);
void	rrotate_r(t_stack **stack_a, t_stack **stack_b, t_logs *logs);
void	chunks_to_b(t_stack **stack_a, t_stack **stack_b,
			int elements_per_chunk, t_logs *logs);
void	find_efficient_el(t_stack **stack_a, t_stack **stack_b,
			t_element *best);
int		min(int a, int b);
int		max(int a, int b);
void	init_el_operations(t_element *el_operations);
int		find_place_a(t_stack **stack_a, t_stack *el, int size);
void	parse_bench(int *bench_mode, char **argv, int *argc);
void	print_bench(t_logs *logs, char *mode, double disorder);
int		handle_two_el_a(t_stack **stack, t_logs *logs);
int		handle_two_el_b(t_stack **stack, t_logs *logs);
void	radix_sort(t_stack **stack_a, t_stack **stack_b, t_logs *logs);
void	bubble_swap(t_stack **stack, t_logs *logs);

#endif