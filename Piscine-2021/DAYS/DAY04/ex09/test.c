#include <stdio.h>

#define SIZE 8

static int solutions;

void	put_queen(int *board, int row);
int	valid(int *board, int row, int col);
void	eight_queens(void);
int	main(void)
{
	eight_queens();
	return (0);
}

void	eight_queens(void)
{
	int	board[SIZE];

	for (int i = 0; i < SIZE; i++) board[i] = -1;
	put_queen(board, 0);
	printf("\n%d solution found.\n", solutions);

}

void	put_queen(int *board, int row)
{
	if (row == SIZE)
	{
		solutions++;
		for (int i = 0; i < SIZE; i++)
			printf("%d", board[i] + 1);
		putchar('\n');
	}
	else
	{
		int	col;
		col = 0;
		while (col < SIZE)
		{
			if (valid(board, row, col))
			{
				board[row] = col;
				put_queen(board, row + 1);
			}
			col++;
		}
	}
}

int	valid(int *board, int row, int col)
{
	int	i;

	i = 0;

	while (i < row)
	{
		if (board[i] == col ||
		    board[i] - i == col - row ||
		    board[i] + i == col + row) return (0);
		else i++;
	}

	return (1);
}
