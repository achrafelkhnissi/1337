/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:02:02 by ael-khni          #+#    #+#             */
/*   Updated: 2021/12/10 14:46:50 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

int	byte[8];

void	display_banner(int pid)
{
	ft_printf("\n\t%s███╗   ███╗██╗███╗   ██╗██╗████████╗ █████╗ ██╗     ██╗  ██╗%s\n", YELLOW, END);
	ft_printf("\t%s██╔████╔██║██║██╔██╗ ██║██║   ██║   ███████║██║     █████╔╝%s \n", YELLOW, END);
	ft_printf("\t%s██║╚██╔╝██║██║██║╚██╗██║██║   ██║   ██╔══██║██║     ██╔═██╗%s \n", YELLOW, END);
	ft_printf("\t%s██║ ╚═╝ ██║██║██║ ╚████║██║   ██║   ██║  ██║███████╗██║  ██╗%s\n", YELLOW, END);
	ft_printf("\t%s╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝%s\n", YELLOW, END);

	ft_printf("%s\n\tPID: %d%s\n", RED, pid, END);
	ft_printf("\t⊱ ────────────────────── {.⋅ ✯ ⋅.} ─────────────────────── ⊰\n\n");
}

int	ft_power(int nb, int power)
{
	int	res;

	res = 1;
	if (power < 0)
		return (0);
	while (power > 0)
	{
		res *= nb;
		power--;
	}
	return (res);
}

int bin_to_char(int *byte)
{
	int res;
	int i;
	int	j;

	i = 8;
	res = 0;
	j = 0;
	while (i--)
		res += byte[j++] * ft_power(2, i);
	return (res);
}

void	func(int sig)
{
	static int	i;
	int c;

	if (sig == SIGUSR1)
		byte[i++] = 0;
	else
		byte[i++] = 1;
	if (i == 8)
	{
		c = bin_to_char(byte);	
		ft_printf("%c", c);
		i = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	display_banner(pid);
	while (1)
	{
		signal(SIGUSR1, func);
		signal(SIGUSR2, func);
		pause();
	}
	return (0);
}
