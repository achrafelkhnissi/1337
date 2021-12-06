/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:41:16 by ael-khni          #+#    #+#             */
/*   Updated: 2021/12/06 22:49:25 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*g_res;
int		g_i = 0;
int		g_bl;
int		g_size;

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	space(char c)
{
	if (c == '\t' || c == '\n' || c == '\f'
		|| c == '\r' || c == ' ' || c == '\v')
		return (1);
	return (0);
}

int	ft_size(int nbr)
{
	int	i;

	if (nbr == 0)
		return (1);
	i = 0;
	while (nbr)
	{
		nbr /= g_bl;
		i++;
	}
	return (i);
}

void	ft_putnbr(int nb, char *b)
{
	unsigned int	nbr_uns;
	unsigned int	ul;
	int				stop;

	ul = (unsigned int)g_bl;
	if (nb < 0)
	{
		nbr_uns = (unsigned int)(nb * -1);
		g_i = 1;
	}
	else
	{
		nbr_uns = (unsigned int)nb;
		g_i = 0;
	}
	stop = g_size;
	while (stop > g_i)
	{
		g_res[--stop] = b[nbr_uns % ul];
		nbr_uns /= ul;
	}
}

char	*ft_putnbr_base(int nbr, char *base)
{
	int		i;

	g_i = 0;
	i = 0;
	g_bl = ft_strlen(base);
	g_size = ft_size(nbr);
	if (nbr < 0)
		g_size++;
	g_res = (char *)malloc((g_size + 1) * sizeof(char));
	g_res[g_size] = '\0';
	if (!g_res)
		return (0);
	if (nbr < 0)
		g_res[0] = '-';
	ft_putnbr(nbr, base);
	return (g_res);
}
