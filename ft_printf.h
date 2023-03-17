/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:39:16 by cormiere          #+#    #+#             */
/*   Updated: 2022/10/17 16:41:47 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int				ft_printf(const char *print, ...);
size_t			ft_putchar(int c);
unsigned int	ft_strlen(char *str);
size_t			ft_putstr(char *s);
size_t			ft_putnbr(int nb);
size_t			ft_putnbr_base(long unsigned int n, char *base);

#endif
