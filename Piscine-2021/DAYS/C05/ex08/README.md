## Exercise 08: The Eight Queens
- The aim of this game is to place eight queens on a chessboard, without the being able to meet in one shot.
- Refresh your memories on chess rules.
- Evidently, recursivity is required to solve this problem.
- Create a function that returns the number of possibilities to place those eight queens on the chessboard without them being able to reach each other.
- Here's how it should be prototyped:
```C
int	ft_eight_queens_puzzle(void);
```
- Your function must return its result in less than two seconds.

## Solution

We divide out program into 4 functions, each functions handle different task
- [ft_eight_queen_puzzle](https://github.com/achrafelkhnissi/Computer-Science/blob/master/1337/DAYS/DAY04/ex09/README.md#ft_eight_queens_puzzle): the main function of the puzzle.
- [put_queen](https://github.com/achrafelkhnissi/Computer-Science/blob/master/1337/DAYS/DAY04/ex09/README.md#put_queen): a function to put a queen in the given position.
- [is_valid](https://github.com/achrafelkhnissi/Computer-Science/blob/master/1337/DAYS/DAY04/ex09/README.md#is_valid): a function is a position if it's valid or not before putting a queen in it.
- print_board: a non-required function to print the board.

### ft_eight_queens_puzzle
This is the simplest function of all of them.
1. We declare an array of the size of a chess board.
2. We declare a variable "solutions" (or any name) to return.
3. We fill the array with (-1) values (just in case.
4. Then we call the __put_queen__ an pass to it two parameters\
  and we assign the return value of __put_queen__ to the variable we declared in (2).
	- The board.
	- 0 (the index of the first row)
5. We return the variable (2) to the main function.

### put_queen
We try to put a queen on the target row\
if a valid place found, the function calls itself trying to place\
a queen on the next row, until all __N__ queens are placed on __NxN__ board.\

This function takes two arguments:
	- An array that represent a chess board.
	- And an int that represent the target row.

1. First we declare a `static` variable to keep track of how many solutions we found\
   and keyword static allows the function to keep its value after each call. 
2. We declare an int variable that represent the columns in the target row and assign it to 0.
3. Because __put_queen__ is a recursive function, we need base case for the function to stop in some point, and in our case we check is the target row == the size of the board. If true we increment (1); else (4)
4. If the previous check is false then we go through a while loop as long as the target column is less than the size of the board.
	- We check if the position is [valid](https://github.com/achrafelkhnissi/Computer-Science/blob/master/1337/DAYS/DAY04/ex09/README.md#is_valid), if True:
	- We put the target column in the target row in the board.
	- and we call __put_queen__ function recursively on the next row.
	- If false: We increment the column.
5. Return (1);

### is_valid
Check if a given position is under attack from any of the previously placed queens.\

This function takes three arguments:
	- An array that represent a chess board.
	- An int that represent the target row.
	- An int that represent the target column.

1. We declare and index variable that represent the index the previous rows.
2. We go through a while loop as long the (1) the previous rows is less than the target row.
3. Inside (2) we check:
	- if the previous column == the target column.
	- or the previous (column - row) == the target (column - row)
	- or the previous (column + row) == the target (column + row)

```
  | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 
--|---|---|---|---|---|---|-–-|---|
0 | Q |   |   |   |   |   |   |   |
--|---|---|---|---|---|---|---|---|
1 |   |   | Q |   |   |   |   |   |
--|---|---|---|---|---|---|---|---|  
2 |   |   |   |   | Q |   |   |   |
--|---|---|---|---|---|---|---|---|  
3 |   |   |   |   |   |   | Q |   |
--|---|---|---|---|---|---|---|---|  
4 |   | Q |   |   |   |   |   |   |
--|---|---|---|---|---|---|---|---|  
5 |   |   |   | Q |   |   |   |   |
--|---|---|---|---|---|---|---|---|  
6 |   |   |   |   |   | Q |   |   |
--|---|---|---|---|---|---|---|---|  
7 |   |   |   |   |   |   |   | N |
--|---|---|---|---|---|---|---|---|

New queen = (7, 7)
1th queen = (0, 0)

note: q+ = (row + col), q- = (row - col)

if (nq row ==  1q row)
then they are in the same row therefore the nq position is not valid.

if (nq+ == 1q+ or nq- == nq-)
then the position is not valid.
```

- Another example
```
  | 0 | 1 | 2 | 3 |
--|---|---|---|---|
0 |   | a |   | x |
--|---|---|---|---|
1 |   |   | Q |   |
--|---|---|---|---|  
2 |   |   |   | b |
--|---|---|---|---|  
3 | y |   |   |   |
--|---|---|---|---|  

Q = r1, c2;

a = r0, c1;
b = r2, c4;

x = r0, c3;
y = r3, c0;

note:
Q+ = x+ and y+;
Q- = a- and b-;
```

4. If one of (3) is true we return (false) means the current position is under attack.
5. else if (3) is false we increment the previous row (1) to check the next previous row.
6. When we go through (2) incrementing the previous row till (1) == the target row, that means the positions is safe so we return 1.

------------------------------------

# Exercise 09: The Eight Queens 2
- Create a function that displays all possible placements of the eight queens on the chessboard, without them being able to reach each other.
- Recursivity is required to solve this problem.
- Here's how it should be prototyped:
```C
void	ft_eight_queens_puzzle.2(void);
```
- Here's how it'll be displayed:
```
$>./a.out 15863724
16837425
17468253
...
```
- The sequence goes from left to right. The first digit represent the first Queen's position in the first column (the index starting from 1). The Nth digit represents the Nth Queen's positions in the Nth column.
- There's a link break after the last solution.
- Your function must return its result in less than two seconds.

## Solution

We divide out program into 4 functions, each functions handle different task
- [ft_eight_queen_puzzle](https://github.com/achrafelkhnissi/Computer-Science/blob/master/1337/DAYS/DAY04/ex09/README.md#ft_eight_queens_puzzle): the main function of the puzzle.
- [put_queen](https://github.com/achrafelkhnissi/Computer-Science/blob/master/1337/DAYS/DAY04/ex09/README.md#put_queen): a function to put a queen in the given position.
- [is_valid](https://github.com/achrafelkhnissi/Computer-Science/blob/master/1337/DAYS/DAY04/ex09/README.md#is_valid): a function is a position if it's valid or not before putting a queen in it.
- print_board: a non-required function to print the board.

### ft_eight_queens_puzzle
This is the simplest function of all of them.
1. We declare an array of the size of a chess board.
2. We declare a variable "solutions" (or any name) to return.
3. We fill the array with (-1) values (just in case.
4. Then we call the __put_queen__ an pass to it two parameters\
  and we assign the return value of __put_queen__ to the variable we declared in (2).
	- The board.
	- 0 (the index of the first row)
5. We return the variable (2) to the main function.

### put_queen
We try to put a queen on the target row\
if a valid place found, the function calls itself trying to place\
a queen on the next row, until all __N__ queens are placed on __NxN__ board.\

This function takes two arguments:
	- An array that represent a chess board.
	- And an int that represent the target row.

1. First we declare a `static` variable to keep track of how many solutions we found\
   and keyword static allows the function to keep its value after each call. 
2. We declare an int variable that represent the columns in the target row and assign it to 0.
3. Because __put_queen__ is a recursive function, we need base case for the function to stop in some point, and in our case we check is the target row == the size of the board. If true we increment (1); else (4)
	- We print the board.
4. If the previous check is false then we go through a while loop as long as the target column is less than the size of the board.
	- We check if the position is [valid](https://github.com/achrafelkhnissi/Computer-Science/blob/master/1337/DAYS/DAY04/ex09/README.md#is_valid), if True:
	- We put the target column in the target row in the board.
	- and we call __put_queen__ function recursively on the next row.
	- If false: We increment the column. (without adding the else condition);
5. Return (1);

### is_valid
Check if a given position is under attack from any of the previously placed queens.\

This function takes three arguments:
	- An array that represent a chess board.
	- An int that represent the target row.
	- An int that represent the target column.

1. We declare and index variable that represent the index the previous rows.
2. We go through a while loop as long the (1) the previous rows is less than the target row.
3. Inside (2) we check:
	- if the previous column == the target column.
	- or the previous (column - row) == the target (column - row)
	- or the previous (column + row) == the target (column + row)

```
  | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 
--|---|---|---|---|---|---|-–-|---|
0 | Q |   |   |   |   |   |   |   |
--|---|---|---|---|---|---|---|---|
1 |   |   | Q |   |   |   |   |   |
--|---|---|---|---|---|---|---|---|  
2 |   |   |   |   | Q |   |   |   |
--|---|---|---|---|---|---|---|---|  
3 |   |   |   |   |   |   | Q |   |
--|---|---|---|---|---|---|---|---|  
4 |   | Q |   |   |   |   |   |   |
--|---|---|---|---|---|---|---|---|  
5 |   |   |   | Q |   |   |   |   |
--|---|---|---|---|---|---|---|---|  
6 |   |   |   |   |   | Q |   |   |
--|---|---|---|---|---|---|---|---|  
7 |   |   |   |   |   |   |   | N |
--|---|---|---|---|---|---|---|---|

New queen = (7, 7)
1th queen = (0, 0)

note: q+ = (row + col), q- = (row - col)

if (nq row ==  1q row)
then they are in the same row therefore the nq position is not valid.

if (nq+ == 1q+ or nq- == nq-)
then the position is not valid.
```

- Another example
```
  | 0 | 1 | 2 | 3 |
--|---|---|---|---|
0 |   | a |   | x |
--|---|---|---|---|
1 |   |   | Q |   |
--|---|---|---|---|  
2 |   |   |   | b |
--|---|---|---|---|  
3 | y |   |   |   |
--|---|---|---|---|  

Q = r1, c2;

a = r0, c1;
b = r2, c4;

x = r0, c3;
y = r3, c0;

note:
Q+ = x+ and y+;
Q- = a- and b-;
```

4. If one of (3) is true we return (false) means the current position is under attack.
5. else if (3) is false we increment the previous row (1) to check the next previous row.
6. When we go through (2) incrementing the previous row till (1) == the target row, that means the positions is safe so we return 1.

## Problems i faced 
- In the __put_queen__ function step (4) when checking if the position is valid, the mistake i made was the i increment the column just when the position is not valid, which is wrong, we need to increment the columns either way.

