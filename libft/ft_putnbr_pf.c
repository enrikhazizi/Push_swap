/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazizi <ehazizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:54:27 by ehazizi           #+#    #+#             */
/*   Updated: 2025/10/27 15:54:27 by ehazizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_nbr(int n)
{
	int		i;
	long	nb;

	nb = n;
	i = 0;
	if (nb <= 0)
		i++;
	while (nb)
	{
		i++;
		nb /= 10;
	}
	return (i);
}

int	ft_putnbr_pf(int n, int fd)
{
	int	count;

	count = count_nbr(n);
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (count);
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n < 10)
		ft_putchar_pf(n + '0', fd);
	else
	{
		ft_putnbr_pf(n / 10, fd);
		ft_putchar_pf((n % 10) + '0', fd);
	}
	return (count);
}
