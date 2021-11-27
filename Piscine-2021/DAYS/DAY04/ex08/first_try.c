#include <stdio.h>

#define SIZE 8
#define R 1
#define C 1

static int queens[8];

int	ft_eight_queens_puzzle(void);
void	print_board(char b[SIZE][SIZE]);
void	put_queen(char b[SIZE][SIZE], int row, int column);
//void	reset_board(char b[SIZE][SIZE], int row, int col);
int	search_and_place(char b[SIZE][SIZE], int row, int column);
int	is_valid_position(char b[SIZE][SIZE], int row, int column);
int	main(void)
{
	ft_eight_queens_puzzle();

	return(0);
}

int	ft_eight_queens_puzzle(void)
{
	int	solutions;
	int	last_queen;
	int	row;
	int	col;

	row = 0;
	col = 0;
	solutions = 0;

	char board[SIZE][SIZE] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};

	/*while (row < 8)
		last_queen = search_and_place(board, row, col);*/
	last_queen = search_and_place(board, row, col);
	printf("last_queen  position = %d %d\n",
			last_queen, queens[last_queen - 1] + 1);
	print_board(board);

	//reset_board(board, last_queen - 1, queens[last_queen - 1]);
	/*last_queen = search_and_place(board, last_queen, queens[last_queen + 1]);
	printf("last_queen  position = %d %d\n",
			last_queen, queens[last_queen - 1] + 1);
	print_board(board);*/

	return(0);
}

int	search_and_place(char b[SIZE][SIZE], int row, int column)
{
    //! matrix = showArray2D(b, rowCursors=[row], colCursors=[column])

	static int queens_count;
	//static int solutions;
	static int	i;
	if (is_valid_position(b, row, column) && row < 8 && i < 8)
	{
		put_queen(b, row, column);
		queens[row] = column;
		queens_count++;
		i = 0;
		while(i < 8)
		{
			if (is_valid_position(b, row + 1, i))
				search_and_place(b, row + 1, i);
			else i++;
		}	
	}
	else if(queens_count == 8) return (queens_count);
	else if(!is_valid_position(b, row, column) && column < 8 && i < 8)
	{
		search_and_place(b, row, column + 1);
	}

	/*if (queens_count < 8 && i ==  8) 
	{
		search_and_place(b, queens_count - 1, queens[queens_count + 1]);
	}*/

	return (queens_count);
}

int	is_valid_position(char b[SIZE][SIZE], int row, int column)
{
	int	valid;

	valid = 1;

	if (b[row][column] == ' ') return (valid);

	return (!valid);
}

/*void	reset_board(char b[SIZE][SIZE], int row, int col)
{
	int	i;
	int	j;

	i = 0;
	j = 0;

	while (i < 8)
	{
		while(j < 8)
		{
			b[i][j] = ' ';
			i++;
		}
		j++;
	}

	while(row > 0)
	{
		put_queen(b, row, col);
		row--;
	}
}*/

void	put_queen(char b[SIZE][SIZE], int row, int column)
{
    //! matrix = showArray2D(b, rowCursors=[r], colCursors=[c])

	int	r;
	int	c;

	b[row][column] = 'Q';

	r  = row;
	c = 0;
	while (c < SIZE) 
		if (c != column) b[r][c++] = '.';
		else c++;

	r = 0;
	c = column;
	while (r < SIZE)
		if (r != row) b[r++][c] = '.';
		else r++;

	r = row;
	c = column;
	while (r > 0 && c > 0) b[--r][--c] = '.';
	r = row;
	c = column;
	while (r < SIZE - 1 && c < SIZE - 1) b[++r][++c] = '.';
	r = row;
	c = column;
	while (r > 0 && c < SIZE - 1) b[--r][++c] = '.';
	r = row;
	c = column;
	while (r < SIZE - 1  && c > 0) b[++r][--c] = '.';
}

void	print_board(char b[SIZE][SIZE])
{
	int	i;
	int	j;

	i = 0; j = 0;

	while(i < 8)
	{
		/* (-1) because the first index in chess
		 * starts with 1 not 0; */
		printf("%d: ", i + 1);
		while(j < 8)
		{
			//printf("%d", j + 1);
			printf("%c ", b[i][j++]);
		}
		putchar('\n');

		j = 0;
		i++;
	}	
}

