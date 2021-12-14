/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:02:02 by ael-khni          #+#    #+#             */
/*   Updated: 2021/12/14 09:19:20 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

void	display_banner(int pid)
{
	ft_printf("\n\t%s███╗   ███╗██╗███╗   ██╗██╗████████╗ █████╗ ██╗     ██╗██╗\
			%s\n", YELLOW, END);
	ft_printf("\t%s██╔████╔██║██║██╔██╗ ██║██║   ██║   ███████║██║     █████╔╝\
			%s \n", YELLOW, END);
	ft_printf("\t%s██║╚██╔╝██║██║██║╚██╗██║██║   ██║   ██╔══██║██║     ██╔═██╗\
			%s \n", YELLOW, END);
	ft_printf("\t%s██║ ╚═╝ ██║██║██║ ╚████║██║   ██║   ██║  ██║███████╗██║  ██╗\
			%s\n", YELLOW, END);
	ft_printf("\t%s╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝\
			%s\n", YELLOW, END);
	ft_printf("%s\n\t\tPID: %d%s\t\t\t%sBy: ael-khni%s\n", RED, pid, END,
		YELLOW, END);
	ft_printf("\t⊱ ────────────────────── {.⋅ ✯ ⋅.} ─────────────────────── ⊰\
			\n\n");
}

void	extended_action(char *c, int *received, int *client_pid, int *i)
{
	ft_printf("%c", *c);
	if (*c == '\0')
	{
		ft_printf("\n%s%d signal recieved from client PID: %d%s\n",
			GREEN, *received, *client_pid, END);
		*received = 0;
		*c = 0;
		kill(*client_pid, SIGUSR1);
		return ;
	}
	*i = 0;
}

void	action(int sig, siginfo_t *info, void *context)
{
	static int	client_pid;
	static int	i;
	static char	c;
	static int	received;
	static int	current_pid;

	(void)context;
	if (!client_pid)
		client_pid = info->si_pid;
	current_pid = info->si_pid;
	if (client_pid != current_pid)
	{
		client_pid = current_pid;
		i = 0;
		c = 0;
		received = 0;
	}
	c |= (sig == SIGUSR2);
	received++;
	i++;
	if (i == 8)
		extended_action(&c, &received, &client_pid, &i);
	c <<= 1;
}

int	main(void)
{
	int					pid;
	struct sigaction	act;

	pid = getpid();
	display_banner(pid);
	act.sa_sigaction = action;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	while (1)
	{
		sigaction(SIGUSR1, &act, 0);
		sigaction(SIGUSR2, &act, 0);
		pause();
	}
	return (0);
}
