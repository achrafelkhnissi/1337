/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 12:54:11 by ael-khni          #+#    #+#             */
/*   Updated: 2021/11/28 09:30:20 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	check(int arr[], int size)
{
	int	i;

	i = size - 1;
	while (i)
	{
		if (arr[i] == arr[i - 1] + 1)
			i--;
		else
			break ;
	}
	return (i - 1);
}

void	reset(int arr[], int size, int index)
{
	arr[index]++;
	index++;
	while (index < size)
	{
		arr[index] = arr[index - 1] + 1;
		index++;
	}
}

void	print_numbers(int arr[], int size)
{
	int	i;

	i = 0;
	while (i < size)
		ft_putchar(arr[i++] + '0');
	if (arr[0] < 10 - size)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_combn(int n)
{
	int	i;
	int	arr[10];

	i = 0;
	while (i < n)
	{
		arr[i] = i;
		i++;
	}
	while (arr[0] <= 10 - n)
	{
		if (arr[n - 1] < 9)
		{
			print_numbers(arr, n);
			arr[n - 1]++;
		}
		else
		{
			print_numbers(arr, n);
			i = check(arr, n);
			if (i < 0)
				break ;
			reset(arr, n, i);
		}
	}
}
