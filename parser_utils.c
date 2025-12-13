/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fqose <frenki.qose@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:35:00 by fqose             #+#    #+#             */
/*   Updated: 2025/12/11 16:35:00 by fqose            ###   ########.al       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_nr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ')
			return (0);
		++i;
	}
	return (1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	set_mode(char **mode, char *str)
{
	if (!str)
		return (0);
	if (ft_strcmp(str, "--simple") == 0)
		*mode = "--simple";
	else if (ft_strcmp(str, "--medium") == 0)
		*mode = "--medium";
	else if (ft_strcmp(str, "--complex") == 0)
		*mode = "--complex";
	else if (ft_strcmp(str, "--adaptive") == 0)
		*mode = "--adaptive";
	else
		return (0);
	return (1);
}

int	create_from_single(char *str, t_stack **whole_stack)
{
	char	**token;
	int		i;
	int		num;

	i = 0;
	token = ft_split(str, ' ');
	if (!token)
		return (0);
	while (token[i])
	{
		if (!ft_atoi_strict(token[i], &num))
			return (0);
		create_list(whole_stack, num);
		++i;
	}
	free_split(token);
	return (1);
}

int	create_from_multi(char **ptr, t_stack **whole_stack)
{
	int	i;
	int	num;

	i = 0;
	while (ptr[i])
	{
		if (!ft_atoi_strict(ptr[i], &num))
			return (0);
		create_list(whole_stack, num);
		++i;
	}
	return (1);
}
