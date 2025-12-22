/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fqose <fqose@student.42.fr>                #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-13 19:18:16 by fqose             #+#    #+#             */
/*   Updated: 2025-10-13 19:18:16 by fqose            ###   ########.al       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	const char	*first;
	char		*second;

	first = (const char *)src;
	second = (char *)dest;
	i = 0;
	if (src < dest && (src + n) > dest)
	{
		while (i < n)
		{
			second[n - i - 1] = first[n - i - 1];
			++i;
		}
	}
	else
	{
		while (i < n)
		{
			second[i] = first[i];
			++i;
		}
	}
	return (dest);
}
