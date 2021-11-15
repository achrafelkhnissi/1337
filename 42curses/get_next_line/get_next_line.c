/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 06:08:05 by ael-khni          #+#    #+#             */
/*   Updated: 2021/11/15 14:28:27 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
 * get_next_line function:
 * 	1. read till BUFF_SIZE and store it in buff.
 * 	2. check if there's a newline in buff
 * 	3. if true we return the buff up to newline
 * 	4. else we join line + buff.
 */

size_t	ft_strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (s[l])
		l++;
	return (l);
}

int	check_newline(char *buff)
{
	int	i;

	i = 0;
	if (!buff)
	{
		printf("check_neline Error: buff = %s\n", buff);
		return (-1);
	}
	while (buff[i])
	{
		if (buff[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		s1_len;
	int		s2_len;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
		str[s1_len++] = s2[i++];
	str[s1_len] = '\0';
	free((void*)s1);
	return (str);
}

char	*ft_strndup(const char *s1, int n)
{
	char	*copy;
	size_t	s1_len;
	int		i;

	i = 0;
	s1_len = ft_strlen(s1);
	copy = malloc(sizeof(char) * (s1_len + 1));
	if (!copy)
		return (NULL);
	while (s1[i] && i < n)
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*get_next_line(int fd)
{
	char	buff[BUFFER_SIZE + 1];
	char	*tmp;
	char	*line;
	int	ret;

	i = 0;
	ret = BUFFER_SIZE;
	tmp = ft_strndup("", 0);
	if (fd == -1 || fd > 8192)
	{
		printf("Error fd\n");
		free(tmp);
		return (NULL);
	}
	while (ret)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret == -1)
		{
			printf("Error: ret %d\n", ret);
			free(tmp);
			return (NULL);
		}
		buff[ret] = 0;
		tmp = ft_strjoin(tmp, buff);
		i = check_newline(tmp);
		if (i)
		{
			line = ft_strndup(tmp, i + 1);	
			free(tmp);
			return (line);
		}
	}
	if (!tmp || !tmp[0])
	{
		free(tmp);
		return (NULL);
	}
	return (tmp);
}
