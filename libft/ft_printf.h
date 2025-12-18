/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazizi <ehazizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:54:16 by ehazizi           #+#    #+#             */
/*   Updated: 2025/10/27 15:54:16 by ehazizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

int	ft_putchar_pf(char c, int fd);

int	ft_putnbr_pf(int n, int fd);

int	ft_putstr_pf(char *s, int fd);

int	ft_printf(int fd, const char *s, ...);

int	ft_putnub_uns_fd(unsigned int n, int fd);

int	ft_puthex_fd(unsigned long n, int fd, char c);

int	print_pointer(void *ptr, int fd);

#endif