/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 11:48:13 by ael-khni          #+#    #+#             */
/*   Updated: 2021/11/20 12:11:37 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*tmp[8192];
	char		buff[BUFFER_SIZE + 1];
	char		*line;
	int			ret;
	int			nl;

	if (!tmp[fd])
		tmp[fd] = ft_strdup("");
	ret = read(fd, buff, BUFFER_SIZE);
	while (ret >= 0)
	{
		buff[ret] = 0;
		tmp[fd] = ft_strjoin(tmp[fd], buff);
		nl = check_newline(tmp[fd]);
		if (nl != -1)
		{
			line = ft_substr(tmp[fd], 0, nl + 1);
			tmp[fd] = get_reminder(tmp[fd], nl + 1);
			return (line);
		}
		else
		{
			if (!ret && !tmp[fd][0])
				break ;
			if (!ret)
			{
				line = tmp[fd];
				tmp[fd] = NULL;
				return (line);
			}
		}
		ret = read(fd, buff, BUFFER_SIZE);
	}
	free(tmp[fd]);
	tmp[fd] = NULL;
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
