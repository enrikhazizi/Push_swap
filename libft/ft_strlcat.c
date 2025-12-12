/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fqose <fqose@student.42.fr>                #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-13 20:05:00 by fqose             #+#    #+#             */
/*   Updated: 2025-10-13 20:05:00 by fqose            ###   ########.al       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	src_len;
	size_t	space_left;

	j = 0;
	i = 0;
	src_len = ft_strlen(src);
	while (dst[j] != '\0' && j < size)
		++j;
	if (j == size)
		return (size + src_len);
	space_left = size - j - 1;
	while (src[i] != '\0' && (space_left - i) > 0)
	{
		dst[j + i] = src[i];
		++i;
	}
	dst[j + i] = '\0';
	return (j + src_len);
}
