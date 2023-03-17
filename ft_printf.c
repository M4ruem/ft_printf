/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 21:38:20 by cormiere          #+#    #+#             */
/*   Updated: 2022/10/25 16:03:37 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_putnbr_base_ptr(long unsigned int n, char *base, int ptr)
{
	unsigned int	result;
	size_t			size;

	result = 0;
	size = 0;
	if (n == 0)
	{
		ft_putstr("(nil)");
		return (5);
	}
	if (ptr == 0)
		size += ft_putstr("0x");
	if (n > (ft_strlen(base) - 1))
		size += ft_putnbr_base_ptr(n / ft_strlen(base), base, 1);
	result = n % ft_strlen(base);
	size += ft_putchar(base[result]);
	return (size);
}

static size_t	first_wood_if(const char *print, va_list args)
{
	int		pos;
	size_t	size;

	size = 0;
	pos = 0;
	if (print[pos + 1] == '%')
		size += ft_putchar('%');
	else if (print[pos + 1] == 'c')
		size += ft_putchar(va_arg(args, int));
	else if (print[pos + 1] == 's')
		size += ft_putstr(va_arg(args, char *));
	else if (print[pos + 1] == 'p')
		size += ft_putnbr_base_ptr(
				va_arg(args, long unsigned int), "0123456789abcdef", 0);
	else if (print[pos + 1] == 'd')
		size += ft_putnbr(va_arg(args, int));
	return (size);
}

static size_t	second_wood_if(const char *print, va_list args)
{
	int		pos;
	size_t	size;

	size = 0;
	pos = 0;
	if (print[pos + 1] == 'i')
		size += ft_putnbr(va_arg(args, int));
	else if (print[pos + 1] == 'u')
		size += ft_putnbr_base(va_arg(args, unsigned int), "0123456789");
	else if (print[pos + 1] == 'x')
		size += ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef");
	else if (print[pos + 1] == 'X')
		size += ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (!print[pos + 1])
	{
		size += ft_putchar('%');
		size += ft_putchar(print[pos + 1]);
	}
	return (size);
}

int	ft_printf(const char *print, ...)
{
	va_list		args;
	int			pos;
	size_t		size;

	va_start(args, print);
	size = 0;
	pos = 0;
	while (print[pos])
	{
		if (print[pos] == '%')
		{
			size += first_wood_if(&print[pos], args);
			size += second_wood_if(&print[pos], args);
			pos++;
		}
		else
			size += ft_putchar(print[pos]);
		pos++;
	}
	va_end(args);
	return (size);
}
