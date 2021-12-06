/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 14:29:14 by ael-khni          #+#    #+#             */
/*   Updated: 2021/12/06 22:48:12 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		g_i;

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!dest || !src)
		return (dest);
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*get_str(int size, char **strs, char *sep)
{
	char	*str;
	int		i;
	int		sep_l;
	int		str_l;

	str_l = 0;
	i = 0;
	if (size == 0)
	{
		str = malloc(sizeof(char));
		*str = 0;
		return (str);
	}
	while (i < size)
	{
		str_l += ft_strlen(strs[i]);
		i++;
	}
	sep_l = ft_strlen(sep) * (size - 1);
	str = malloc(sizeof(char) * (str_l + sep_l));
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		j;
	int		k;
	char	*str;

	str = get_str(size, strs, sep);
	g_i = 0;
	k = 0;
	while (g_i < size)
	{
		j = 0;
		while (strs[g_i][j])
		{
			str[k++] = strs[g_i][j];
			j++;
		}
		j = 0;
		while (sep[j] && g_i != size - 1)
		{
			str[k++] = sep[j];
			j++;
		}
		g_i++;
	}
	str[k] = '\0';
	return (str);
}
