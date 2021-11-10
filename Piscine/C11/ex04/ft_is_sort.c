/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:18:50 by ael-khni          #+#    #+#             */
/*   Updated: 2021/10/13 08:06:00 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	pus;
	int	neg;
	int	i;

	pus = 0;
	neg = 0;
	i = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) <= 0)
			neg++;
		if (f(tab[i], tab[i + 1]) >= 0)
			pus++;
		i++;
	}
	if (pus == i || neg == i)
		return (1);
	return (0);
}
