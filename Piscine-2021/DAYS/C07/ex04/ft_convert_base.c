/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:40:11 by ael-khni          #+#    #+#             */
/*   Updated: 2021/12/06 22:49:00 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	*ft_putnbr_base(int nbr, char *base);
int		space(char c);
int	g_bl;
int	g_res;
int	g_sig;
int	g_i;

void	start(char *str)
{
	g_sig = 1;
	g_i = 0;
	while (str[g_i] == '\t' || str[g_i] == '\n' || str[g_i] == '\f'
		|| str[g_i] == '\r' || str[g_i] == ' ' || str[g_i] == '\v'
		|| str[g_i] == '+' || str[g_i] == '-')
	{
		if (str[g_i] == '+' || str[g_i] == '-')
		{
			if (str[g_i] == '-')
				g_sig *= -1;
		}
		g_i++;
	}
}

int	valid(char *str)
{
	int	i;
	int	j;
	int	count;

	if (str[0] == '\0' || str[1] == '\0')
		return (0);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+' || space(str[i]))
			return (0);
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	pos(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	g_bl = 0;
	g_res = 0;
	if (!str || !base)
		return (0);
	while (base[g_bl])
		g_bl++;
	if (valid(base))
	{
		start(str);
		while (str[g_i] && pos(base, str[g_i]) != -1)
		{
			g_res = (g_res * g_bl) + pos(base, str[g_i]);
			g_i++;
		}
	}
	return (g_res * g_sig);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*output;
	int		a;

	if (!nbr || !(valid(base_from)) || !(valid(base_to)))
		return (0);
	a = ft_atoi_base(nbr, base_from);
	output = ft_putnbr_base(a, base_to);
	return (output);
}
