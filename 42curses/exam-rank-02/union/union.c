/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:17:23 by ael-khni          #+#    #+#             */
/*   Updated: 2022/02/09 13:17:48 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    put_uniq(char *s, int *exist, int size)
{
    while (*s)
    {
        if (!exist[(int)*s])
        {
            write(1, s, 1);
            exist[(int)*s] = 1;
        }
        s++;
    }
}

int main(int ac, char **av)
{
    if (ac == 3)
    {
        int exist[255] = {0};
        char *s1 = av[1];
        char *s2 = av[2];
        put_uniq(s1, exist, 255);
        put_uniq(s2, exist, 255);
    }
    write(1, "\n", 1);
    return (0);
}
