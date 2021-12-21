/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:13:08 by ael-khni          #+#    #+#             */
/*   Updated: 2021/12/21 12:30:27 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putaddr_hex(unsigned long int nbr, char Xx, int *len)
{
	unsigned long int	base_len;
	char				*base;

	base_len = 16;
	if (Xx == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nbr < base_len)
		ft_putchar(base[nbr % base_len], len);
	else
	{
		ft_putaddr_hex(nbr / base_len, Xx, len);
		ft_putaddr_hex(nbr % base_len, Xx, len);
	}
}

void	ft_putaddr(void *addr, int *len)
{
	unsigned long int	ptr;

	ptr = (unsigned long int)addr;
	ft_putstr("0x", len);
	ft_putaddr_hex(ptr, 'x', len);
}
