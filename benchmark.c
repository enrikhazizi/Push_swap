/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fqose <frenki.qose@learner.42.tech>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-15 20:36:00 by fqose             #+#    #+#             */
/*   Updated: 2025-12-15 20:36:00 by fqose            ###   ########.al       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_bench(int *bench_mode, char **argv, int argc)
{
	int	i;

	i = 1;
	if (ft_strcmp(argv[1], "--bench") == 0)
	{
		*bench_mode = 1;
		while (i < argc)
		{
			argv[i] = argv[i + 1];
			++i;
		}
	}
}

void	print_disorder_per(double disorder)
{
	int integer;
	int decimal;
	int scaled;

	scaled = (int)(disorder * 10000 + 0.5);
	integer = scaled / 100;
	decimal = scaled % 100;
	ft_printf(2, "[bench] disorder:  %d.", integer);
	if (decimal < 10)
		ft_printf(2, "0");
	ft_printf(2, "%d%%\n", decimal);
}

void	print_bench(t_logs *logs, char *mode, double disorder)
{
	char *strategy;

	print_disorder_per(disorder);
	if (ft_strcmp(mode, "--simple") == 0)
		strategy = "Simple / O(n²)\n";
	else if (ft_strcmp(mode, "--medium") == 0)
		strategy = "Medium / O(n√n)\n";
	else if (ft_strcmp(mode, "--complex") == 0)
		strategy = "Complex / O(n log n)\n";
	else if (ft_strcmp(mode, "--adaptive") == 0)
		strategy = "Adaptive / ";
	ft_printf(2, "[bench] strategy:  %s", strategy);
	if (ft_strcmp(mode, "--adaptive") == 0)
	{
		if (disorder < 0.2)
			ft_printf(2, "O(n²)\n");
		else if (disorder < 0.5)
			ft_printf(2, "O(n√n)\n");
		else
			ft_printf(2, "O(n log n)\n");
	}
	ft_printf(2, "[bench] total_ops:  %d\n", logs->total);
	ft_printf(2, "[bench] sa:  %d  sb:  %d  ss:  %d  pa:  %d  pb:  %d\n",
			logs->sa, logs->sb, logs->ss, logs->pa, logs->pb);
	ft_printf(2, "[bench] ra:  %d  rb:  %d  rr:  %d  rra:  %d  rrb:  %d  rrr:   %d\n",
			logs->ra, logs->rb, logs->rr, logs->rra, logs->rrb, logs->rrr);
}
