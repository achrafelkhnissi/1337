/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_valid2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:42:16 by ael-khni          #+#    #+#             */
/*   Updated: 2021/10/13 17:42:19 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include "global_vars.h"

void	ft_extract(char *str)
{
	int	len;
	int	i;
	int	count;

	count = 2;
	len = ft_strlen(str);
	if (len < 4)
		return ;
	i = len - 1;
	while (count >= 0)
		g_chars[count--] = str[i--];
	g_y = ft_atoi(str, i);
}

int	ft_length(char **map)
{
	int	i;

	g_x = ft_strlen(map[1]);
	i = 1;
	while (i < g_y)
	{
		if (ft_strlen(map[i]) != g_x)
			return (0);
		i++;
	}
	return (1);
}

int	ft_break(char **map)
{
	int	i;

	i = 1;
	while (map[i])
		i++;
	if (i - 1 != g_y)
		return (0);
	return (1);
}
