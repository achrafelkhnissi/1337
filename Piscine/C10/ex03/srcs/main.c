/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:57:31 by ael-khni          #+#    #+#             */
/*   Updated: 2021/10/11 10:53:45 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_hex(int nbr)
{
	unsigned int	n;

	n = nbr;
	if (nbr < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n < 16)
		ft_putchar("0123456789abcdef"[n % 16]);
	else
	{
		ft_putnbr_hex(n / 16);
		ft_putnbr_hex(n % 16);
	}
}

void	print_hex(char *str, int flag)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if ((i == 16 / 2 && flag) || (i == 0 && flag))
			write(1, " ", 1);
		ft_putnbr_hex(str[i++]);
		write(1, " ", 1);
	}
}

void	print_addr(int i, int flag)
{
	if (flag && i < 0xfffffff)
		ft_putnbr_hex(0);
	if (i < 0xffffff)
		ft_putnbr_hex(0);
	if (i < 0xfffff)
		ft_putnbr_hex(0);
	if (i < 0xffff)
		ft_putnbr_hex(0);
	if (i < 0xfff)
		ft_putnbr_hex(0);
	if (i < 0xff)
		ft_putnbr_hex(0);
	if (i < 0xf)
		ft_putnbr_hex(0);
	ft_putnbr_hex(i);
}

void	print_str(char *str)
{
	int	i;

	i = 0;
	write(1, "|", 1);
	while (i < 16)
		write(1, &str[i++], 1);
	write(1, "|", 1);
}

int	main(int ac, char **av)
{
	print_addr(atoi(av[1]), atoi(av[2]));	
	write(1, " ", 1);
	print_hex("future is loading", atoi(av[2]));
	if (atoi(av[2]))
	{
		write(1, " ", 1);
		print_str("future is loading");
	}
	putchar('\n');
	return (0);
}
