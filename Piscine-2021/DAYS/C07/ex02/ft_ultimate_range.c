/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:28:09 by ael-khni          #+#    #+#             */
/*   Updated: 2021/12/06 22:47:28 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	arr_size(int min, int max)
{
	int	i;

	i = 0;
	if (min >= max)
		return (-1);
	while (min < max)
	{
		i++;
		min++;
	}
	return (i);
}

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	len;
	int	*tab;

	i = 0;
	len = arr_size(min, max);
	if (len < 0)
	{
		*range = NULL;
		return (0);
	}
	tab = malloc(sizeof(int) * len);
	if (!tab)
		return (-1);
	while (i < len)
	{
		tab[i] = min;
		min++;
		i++;
	}
	*range = tab;
	return (len);

