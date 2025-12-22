/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fqose <fqose@student.42.fr>                #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-13 23:37:42 by fqose             #+#    #+#             */
/*   Updated: 2025-10-13 23:37:42 by fqose            ###   ########.al       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new;
	int		length;
	int		i;

	i = 0;
	length = 0;
	if (!s)
		return (0);
	while (s[length] != '\0')
		++length;
	new = malloc(sizeof(char) * (length + 1));
	if (!new)
		return (0);
	while (i < length)
	{
		new[i] = s[i];
		++i;
	}
	new[i] = '\0';
	return (new);
}
