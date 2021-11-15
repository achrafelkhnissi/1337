/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 06:34:08 by ael-khni          #+#    #+#             */
/*   Updated: 2021/11/15 14:28:32 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int ac, char **av)
{
	int	fd;
	char	*line;

	if (ac != 2)
		return (1);
	fd = open(av[1], O_RDWR);
	if (fd == -1 || fd > 1023)
	{
		printf("Error fd\n");
		return (-1);
	}
	int	True = 1;
	while (True)
	{
		line = get_next_line(fd);
		if (!line)
		{
			printf("end of file\n");
			True = 0;
			break ;
		}
		printf("%s\n", line);
	}
	return (0);
}
