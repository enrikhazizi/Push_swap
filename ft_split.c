/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazizi <ehazizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 17:12:52 by ehazizi           #+#    #+#             */
/*   Updated: 2025/12/10 17:12:53 by ehazizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_space(char c)
{
	if (c == ' ')
		return (1);
	return (0);
}

int	count_words(char *str)
{
	int	count;
	int	i;
	int	flag;

	i = 0;
	count = 0;
	flag = 0;
	while (str[i])
	{
		if (!flag && !is_space(str[i]))
		{
			count++;
			flag = 1;
		}
		if (is_space(str[i]) && flag)
			flag = 0;
		i++;
	}
	return (count);
}

char	*ft_strcpy(char *str)
{
	int		i;
	char	*word;

	i = 0;
	while (str[i] && !is_space(str[i]))
		i++;
	word = malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (str[i] && !is_space(str[i]))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str)
{
	int		words_len;
	int		i;
	int		j;
	char	**words;

	i = 0;
	j = 0;
	words_len = count_words(str);
	words = malloc(sizeof(char *) * (words_len + 1));
	if (!words)
		return (NULL);
	while (str[i])
	{
		if (!is_space(str[i]))
		{
			words[j] = ft_strcpy(&str[i]);
			while (str[i] && !is_space(str[i]))
				i++;
			j++;
		}
		else
			i++;
	}
	words[j] = 0;
	return (words);
}
