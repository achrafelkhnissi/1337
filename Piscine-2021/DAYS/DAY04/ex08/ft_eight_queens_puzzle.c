#include <stdio.h>

#define SIZE 8

void	print_board(int *b, int size);
int	put_queen(int *b, int row);
int	ft_eight_queens_puzzle(void);
int	is_valid(int *board, int row, int col);

int	main(void)
{
	printf("Found %d solutions\n", ft_eight_queens_puzzle());
	return (0);
}

int	ft_eight_queens_puzzle(void)
{
	int	board[SIZE];
	int	i;

	i = 0;
	/* putting (-1) on each position */
	while (i < SIZE)
		board[i++] = -1;
	return (put_queen(board, 0));
}

/* Try to put queen on target row
 * if a valid place found, the function calls itself trying to place
 * a queen on the next row, until all N queens are placed on NxN board.*/
int	put_queen(int *b, int row)
{
	static int solutions;
	/* base (stop) case - all N rows are occupied */
	if (row == SIZE)
		solutions++;
		//printf("Solution %d:\n", solutions);
		//print_board(b, SIZE);
		//putchar('\n');
	else
	{
		int	col;

		col = 0;
		while (col < SIZE)
		{
			/* Reject all invalid positions */
			if (is_valid(b, row, col))
			{
				b[row] = col;
				put_queen(b, row + 1);
			}
			col++;
		}
	}
	return (solutions);
}

/* Check if a given position is under attach from 
 * any of the previously placed queens */
int	is_valid(int *board, int row, int col)
{
	int	i;

	i = 0;
	while (i < row)
		if (board[i] == col || board[i] - i == col - row ||
				board[i] + i == col + row)
			return (0);
		else i++;

	return (1);
}

void	print_board(int *b, int size)
{
	int	r;
	int	c;

	r = 0;
	while(r < size)
	{
		c = 0;
		while(c < size)
		{
			if (b[r] == c)
				printf("Q ");
			else 
				printf(". ");
			c++;

		}
		putchar('\n');
		r++;
	}
}
