/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 20:38:27 by ael-khni          #+#    #+#             */
/*   Updated: 2021/12/10 14:46:57 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

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
		usleep(100);
	}
}

void	sent_text(char *str, int pid)
{
	int i;

	i = 0;
	while (str[i])
		char_to_bin(str[i++], pid);
}

int main(int ac, char **av)
{
	if (ac == 3)
	{
		int pid = atoi(av[1]);	
		sent_text(av[2], pid);
	}
	return (0);
}
