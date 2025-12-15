/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazizi <ehazizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:52:44 by ehazizi           #+#    #+#             */
/*   Updated: 2025/10/27 15:52:44 by ehazizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_printer(const char *s, va_list ap)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (s[i] == 'd' || s[i] == 'i')
		count += ft_putnbr_pf(va_arg(ap, int), 1);
	else if (s[i] == '%')
		count += ft_putchar_pf(s[i], 1);
	else if (s[i] == 's')
		count += ft_putstr_pf(va_arg(ap, char *), 1);
	else if (s[i] == 'c')
		count += ft_putchar_pf(va_arg(ap, int), 1);
	else if (s[i] == 'u')
		count += ft_putnub_uns_fd(va_arg(ap, unsigned int), 1);
	else if (s[i] == 'x')
		count += ft_puthex_fd(va_arg(ap, unsigned int), 1, 'x');
	else if (s[i] == 'X')
		count += ft_puthex_fd(va_arg(ap, unsigned int), 1, 'X');
	else if (s[i] == 'p')
		count += print_pointer(va_arg(ap, void *));
	else if (s[i] == 'a')
		count += ft_putstr_pf("ketlina na boni reivew", 1);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	ap;

	va_start(ap, s);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			count += format_printer(&s[i], ap);
		}
		else
			count += ft_putchar_pf(s[i], 1);
		i++;
	}
	va_end(ap);
	return (count);
}
