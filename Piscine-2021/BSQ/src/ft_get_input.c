/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:38:17 by ael-khni          #+#    #+#             */
/*   Updated: 2021/10/13 17:52:20 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include "global_vars.h"

char	**stdin_to_stdout(void)
{
	char	*buff;
	char	**map;
	char	c;
	int		i;

	i = 0;
	buff = (char *)malloc(1001051 * sizeof(char));
	if (buff == 0)
		return (0);
	c = 't';
	while (c != 0 && i <= 1001050)
	{
		read(STDIN_FILENO, &c, 1);
		buff[i++] = c;
	}
	buff[i] = '\0';
	map = ft_split(buff, "\n");
	free(buff);
	return (map);
}

void	ft_fill_buffer(char *buff, int read_size, char *input)
{
	int	fd;
	int	ret;

	fd = open(input, O_RDWR);
	buff = (char *)malloc((read_size + 1) * sizeof(char));
	ret = read(fd, buff, read_size);
	buff[ret] = 0;
}

char	**read_input(char *input)
{
	char	**map;
	char	*buff;
	int		fd;
	int		ret;
	int		read_size;

	fd = open(input, O_RDWR);
	if (fd < 0)
		return (0);
	read_size = 0;
	buff = (char *)malloc(g_size * sizeof(char));
	ret = read(fd, buff, g_size);
	if (!ret)
		return (0);
	while (ret)
	{
		read_size += ret;
		ret = read(fd, buff, g_size);
	}
	close(fd);
	ft_fill_buffer(buff, read_size, input);
	map = ft_split(buff, "\n");
	free(buff);
	return (map);
}
