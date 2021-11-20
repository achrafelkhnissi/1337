/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 06:08:05 by ael-khni          #+#    #+#             */
/*   Updated: 2021/11/20 13:59:43 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*tmp;
	char		buff[BUFFER_SIZE + 1];
	char		*line;
	int			ret;
	int			nl;

	if (!tmp)
		tmp = ft_strdup("");
	ret = read(fd, buff, BUFFER_SIZE);
	while (ret >= 0)
	{
		buff[ret] = 0;
		tmp = ft_strjoin(tmp, buff);
		nl = check_newline(tmp);
		if (nl != -1)
		{
			line = ft_substr(tmp, 0, nl + 1);
			tmp = get_reminder(tmp, nl + 1);
			return (line);
		}
		if (!ret && !tmp[0])
			break ;
		if (!ret)
		{
			line = tmp;
			tmp = NULL;
			return (line);
		}
		ret = read(fd, buff, BUFFER_SIZE);
	}
	free(tmp);
	tmp = NULL;
	return (NULL);
}

char	*get_reminder(char *str, int nl)
{
	char	*reminder;
	int		rlen;

	rlen = ft_strlen(str + nl);
	reminder = ft_substr(str, nl, rlen);
	free(str);
	return (reminder);
}

int	check_newline(char *buff)
{
	int	i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

size_t	ft_strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (s[l])
		l++;
	return (l);
}
