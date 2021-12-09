/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signaltest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:05:50 by ael-khni          #+#    #+#             */
/*   Updated: 2021/12/09 11:41:17 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	handler(int num)
{
	printf("Num = %d, I won't die!\n", num);
}

int	main(void)
{
	signal(SIGINT, handler); // 2: SIGINT -> terminate process -> interrupt program
	signal(SIGKILL, handler); // 9: SIGKILL -> terminate process -> kill program,  SIGKILL can't be handeled.
	signal(SIGTERM, handler); // 15: SIGTERM -> terminate process -> software termination signal
	while (1)
	{
		printf("Wasting your cycles. PID = %d\n", getpid());
		sleep(1);
	}
}

// SIGUSR1:
// SIGUSR2:
