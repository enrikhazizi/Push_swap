/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fqose <fqose@student.42.fr>                #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-13 23:24:40 by fqose             #+#    #+#             */
/*   Updated: 2025-10-13 23:24:40 by fqose            ###   ########.al       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t				i;
	size_t				total;
	unsigned char		*init;

	i = 0;
	if (size != 0 && nmemb > (size_t)-1 / size)
		return (0);
	total = nmemb * size;
	init = malloc(total);
	if (!init)
		return (0);
	while (i < total)
	{
		init[i] = 0;
		++i;
	}
	return ((void *)init);
}
