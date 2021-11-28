/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 07:38:11 by ael-khni          #+#    #+#             */
/*   Updated: 2021/11/28 12:54:14 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	convert(char *str, int i)
{
	int	res;

	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10;
		res = res + str[i] - 48;
		i++;
	}
	return (res);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	res;
	int	min;

	i = 0;
	res = 0;
	min = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			min++;
		i++;
	}
	if (min % 2)
		sign = -1;
	res = convert(str, i);
	return (res * sign);
}
