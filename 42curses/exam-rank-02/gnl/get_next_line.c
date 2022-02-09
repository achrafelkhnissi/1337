/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:14:32 by ael-khni          #+#    #+#             */
/*   Updated: 2022/02/09 13:14:34 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return (i);
}

char    *ft_strdup(char *str)
{
    int i = -1;
    char *dup = malloc(sizeof(char) * (ft_strlen(str) + 1));
    if (!dup)
        return (NULL);
    while (str[++i])
        dup[i] = str[i];
    dup[i] = '\0';
    return (dup);
}

char    *get_next_line(int fd)
{
    char    line[8000000];
    char    buf;
    int     i;

    i = 0;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    while (read(fd, &buf, 1) == 1)
    {
        line[i++] = buf;
        if (buf == '\n')
            break ;
    }
    line[i] = '\0';
    if (!line[0])
        return (NULL);
    return (ft_strdup(line));
}
