/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fqose <fqose@student.42.fr>                #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-13 19:08:38 by fqose             #+#    #+#             */
/*   Updated: 2025-10-13 19:08:38 by fqose            ###   ########.al       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	const char	*first;
	char		*second;

	first = (const char *)src;
	second = (char *)dest;
	i = 0;
	while (i < n)
	{
		second[i] = first[i];
		++i;
	}
	return (dest);
}
