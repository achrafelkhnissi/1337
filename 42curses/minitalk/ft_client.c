/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 20:38:27 by ael-khni          #+#    #+#             */
/*   Updated: 2021/12/14 09:18:51 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

static int	g_sent;

void	char_to_bin(unsigned char c, int pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & 128)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		c <<= 1;
		bit++;
		g_sent++;
		usleep(100);
	}
}

void	sent_text(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
		char_to_bin(str[i++], pid);
	char_to_bin('\0', pid);
}

void	recieved(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("%s%d signal sent successfully!%s\n", GREEN, g_sent, END);
	exit(1);
}

int	main(int ac, char **av)
{
	int	server_pid;
	int	client_pid;

	client_pid = getpid();
	if (ac == 3)
	{
		ft_printf("%sclinet pid: %d%s\n", RED, client_pid, END);
		signal(SIGUSR1, recieved);
		server_pid = atoi(av[1]);
		ft_printf("%sText currently sending.. %s\n", YELLOW, END);
		sent_text(av[2], server_pid);
		sleep(3);
	}
	else
		ft_printf("%susage: ./client <server_pid> <text to send>%s\n",
			RED, END);
	return (0);
}
