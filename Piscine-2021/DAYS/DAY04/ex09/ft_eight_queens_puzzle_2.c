#include <stdio.h>

#define SIZE 8

void	print_board(int *b, int size);
void	put_queen(int *b, int row);
void	ft_eight_queens_puzzle(void);
int	is_valid(int *board, int row, int col);
int	main(void)
{
	ft_eight_queens_puzzle();
	return (0);
}

void	ft_eight_queens_puzzle(void)
{
	int	board[SIZE];
	int	i;

	i = 0;
	/* putting (-1) on each position */
	while (i < SIZE) board[i++] = -1;

	put_queen(board, 0);
}

/* Try to put queen on target row
 * if a valid place found, the function calls itself trying to place
 * a queen on the next row, until all N queens are placed on NxN board.*/
void	put_queen(int *b, int row)
{
	/* base (stop) case - all N rows are occupied */
	if (row == SIZE)
	{
		int	i;

		i = 0;
		while (i < SIZE)
			printf("%d", b[i++] + 1);
		putchar('\n');
	}
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
}

/* Check if a given position is under attach from 
 * any of the previously placed queens */
int	is_valid(int *board, int row, int col)
{
	int	i;

	i = 0;
	while (i < row)
		if (board[i] == col || board[i] - i == col - row ||
				board[i] + i == col + row) return (0);
		else i++;

	return (1);

	/*
	 *    0 1 2 3
	 * 0 | |a| |x|
	 * 1 | | |Q| |
	 * 2 | | | |b|
	 * 3 |y| | | |
	 *
	 * q = 1, 2
	 *
	 * a = 0, 1
	 * b = 2, 3
	 *
	 * x = 0, 3
	 * y = 3, 0
	 *
	 * note: q+ == 1 + 2 and q- = 1 - 2
	 *
	 * if a+ == q+ or a- == q- 
	 * then the position is not valid.
	 *
	 * or if |qr - ar| == |qc - ac| //another approach
	 * note: qr = q row, qc = q column
	 *
	 * q+ = x+ and y+
	 * q- = a- and b-
	 */
}

/*
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
			if (b[r] == c) printf("Q ");
			else printf(". ");
			c++;

		}
		putchar('\n');
		r++;
	}
}
*/
