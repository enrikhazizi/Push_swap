/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fqose <fqose@student.42.fr>                #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-13 22:01:16 by fqose             #+#    #+#             */
/*   Updated: 2025-10-13 22:01:16 by fqose            ###   ########.al       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_memcmp_chr(unsigned char c1, unsigned char c2)
{
	return (c1 - c2);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*str1;
	const unsigned char	*str2;

	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (ft_memcmp_chr(str1[i], str2[i]) != 0)
			return (ft_memcmp_chr(str1[i], str2[i]));
		++i;
	}
	return (0);
}
