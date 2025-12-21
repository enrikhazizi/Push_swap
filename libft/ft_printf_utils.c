/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazizi <ehazizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:52:11 by ehazizi           #+#    #+#             */
/*   Updated: 2025/10/27 16:27:37 by ehazizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnub_uns_fd(unsigned int n, int fd)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putnub_uns_fd(n / 10, fd);
	count += ft_putchar_pf((n % 10) + '0', fd);
	return (count);
}

int	ft_puthex_fd(unsigned long n, int fd, char c)
{
	char	*base;
	int		count;

	count = 0;
	if (c == 'x')
		base = "0123456789abcdef";
	if (c == 'X')
		base = "0123456789ABCDEF";
	if (n >= 16)
		count += ft_puthex_fd(n / 16, fd, c);
	count += ft_putchar_pf(base[n % 16], fd);
	return (count);
}

int	print_pointer(void *ptr, int fd)
{
	unsigned long	addr;
	int				count;

	count = 0;
	addr = (unsigned long)ptr;
	if (addr == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	count += ft_puthex_fd(addr, fd, 'x');
	return (count + 2);
}
