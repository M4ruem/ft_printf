/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:47:51 by cormiere          #+#    #+#             */
/*   Updated: 2022/10/25 15:49:00 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

unsigned int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_putstr(char *s)
{
	size_t	i;

	i = 0;
	if (s == 0)
	{
		write(1, "(null)", 6);
		return (6);
	}
	if (!s)
		return (0);
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

size_t	ft_putnbr(int nb)
{
	int			resultat;
	size_t		size;

	resultat = 0;
	size = 0;
	if (nb == -2147483648)
		size += ft_putstr("-2147483648");
	else
	{
		if (nb < 0)
		{
			size += ft_putchar('-');
			nb = nb * -1;
		}
		if (nb > 9)
			size += ft_putnbr(nb / 10);
		resultat = nb % 10 + 48;
		size += ft_putchar(resultat);
	}
	return (size);
}

size_t	ft_putnbr_base(long unsigned int n, char *base)
{
	unsigned int	result;
	size_t			size;

	result = 0;
	size = 0;
	if (n > (ft_strlen(base) - 1))
		size += ft_putnbr_base(n / ft_strlen(base), base);
	result = n % ft_strlen(base);
	size += ft_putchar(base[result]);
	return (size);
}
