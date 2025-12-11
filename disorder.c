/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fqose <frenki.qose@learner.42.tech>         +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 22:00:00 by fqose             #+#    #+#             */
/*   Updated: 2025/12/11 22:00:00 by fqose            ###   ########.al       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static double	compute_disorder_inner(t_stack **j_node, t_stack **i_node,
	size_t *total_pairs, size_t *mistakes)
{
	*total_pairs++;
	if ((*i_node)->data > (*j_node)->data)
		*mistakes++;
	*j_node = (*j_node)->next;
}

double	compute_disorder(t_stack *first)
{
	t_stack	*i_node;
	t_stack	*j_node;
	size_t	total_pairs;
	size_t	mistakes;

	if (!first || first->next == first)
		return (0.0);
	total_pairs = 0;
	mistakes = 0;
	i_node = first;
	while (1)
	{
		j_node = i_node->next;
		while (j_node != first)
			compute_disorder_inner(&j_node, &i_node, &total_pairs, &mistakes);
		i_node = i_node->next;
		if (i_node == first)
			break ;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((double)mistakes / (double)total_pairs);
}
