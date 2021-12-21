/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 19:54:56 by ael-khni          #+#    #+#             */
/*   Updated: 2021/12/21 12:24:23 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_flags(va_list args, const char format, int *len)
{
	if (format == 'd' || format == 'i')
		ft_putnbr(va_arg(args, int), len);
	else if (format == 'u')
		ft_putnbr_u(va_arg(args, unsigned int), len);
	else if (format == 'c')
		ft_putchar((char)va_arg(args, int), len);
	else if (format == 's')
		ft_putstr(va_arg(args, char *), len);
	else if (format == '%')
		ft_putchar(format, len);
	else if (format == 'x')
		ft_putnbr_base(va_arg(args, int), format, len);
	else if (format == 'X')
		ft_putnbr_base(va_arg(args, int), format, len);
	else if (format == 'p')
		ft_putaddr(va_arg(args, void *), len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			check_flags(args, *format, &len);
		}
		else
			ft_putchar(*format, &len);
		format++;
	}
	va_end(args);
	return (len);
}
