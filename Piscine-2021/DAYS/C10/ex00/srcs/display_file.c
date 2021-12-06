/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 19:07:15 by ael-khni          #+#    #+#             */
/*   Updated: 2021/12/06 22:25:04 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>


void	display_file(char *file_name)
{
	int	fd;
	char buf;

	fd = open(file_name, O_RDONLY);
	if (fd > 0)
		while (read(fd, &buf, 1))
			write(1, &buf, 1);
	close(fd);
}
