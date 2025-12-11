/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fqose <fqose@student.42.fr>                #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-13 21:15:13 by fqose             #+#    #+#             */
/*   Updated: 2025-10-13 21:15:13 by fqose            ###   ########.al       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*found;

	found = NULL;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			found = ((char *)&s[i]);
		++i;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (found);
}
