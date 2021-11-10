/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 12:21:23 by ael-khni          #+#    #+#             */
/*   Updated: 2021/10/03 14:18:21 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define SIZE 10

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_position(int *board)
{
	int	i;

	i = 0;
	while (i < SIZE)
		ft_putchar(board[i++] + 48);
	ft_putchar('\n');
}

int	is_valid(int *board, int row, int col)
{
	int	i;

	i = 0;
	while (i < row)
	{
		if (board[i] == col || board[i] - i == col - row
			|| board[i] + i == col + row)
			return (0);
		else
			i++;
	}
	return (1);
}

int	put_queen(int *board, int row)
{
	static int	pos;
	int			col;

	if (row == SIZE)
	{
		pos++;
		print_position(board);
	}
	else
	{
		col = 0;
		while (col < SIZE)
		{
			if (is_valid(board, row, col))
			{
				board[row] = col;
				put_queen(board, row + 1);
			}
			col++;
		}
	}
	return (pos);
}

int	ft_ten_queens_puzzle(void)
{
	int	board[SIZE];
	int	row;

	row = 0;
	while (row < SIZE)
	{
		board[row] = -1;
		row++;
	}
	row = 0;
	return (put_queen(board, row));
}
