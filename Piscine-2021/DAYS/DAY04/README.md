# LIST OF DAY04 EXERCISES

|Exercise        |Description                    |Solution                     |
|-------------|-------------------------------|-----------------------------|
|[ex00](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY04/ex00)      |[iterative factorial](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY04/ex00/README.md)          |[ft_iterative_factorial.c](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY04/ex00/ft_iterative_factorial.c) |
|[ex01](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY04/ex01)     |[recursive factorial](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY04/ex01/README.md)  |[ft_recursive_factorial.c](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY04/ex01/ft_recursive_factorial.c)  |
|[ex02](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY04/ex02)   |[iterative power](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY04/ex02/README.md)           |[ft_iterative_power.c](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY04/ex02/ft_iterative_power.c)         |
|[ex03](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY04/ex03)   |[recursive power](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY04/ex03/README.md)           |[ft_recursive_power.c](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY04/ex03/ft_recursive_power.c)      |
|[ex04](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY04/ex04)   |[fibonacci](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY04/ex04/README.md)        |[ft_fibonacci.c](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY04/ex04/ft_fibonacci.c)  |
|[ex05](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY04/ex05)   |[square root](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY04/ex05/README.md)       |[ft_sqrt.c](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY04/ex05/ft_sqrt.c)       |
|[ex06](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY04/ex06)   |[is prime](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY04/ex06/README.md)           |[ft_is_prime.c](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY04/ex06/ft_is_prime.c) |
|[ex07](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY04/ex07)   |[find next prime](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY04/ex07/README.md)        |[ft_find_next_prime.c](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY04/ex07/ft_find_next_prime.c)       |
|[ex08](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY04/ex08)   |[The Eight Queens](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY04/ex08/README.md)     |[ft_eight_queens_puzzle.c](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY04/ex08/ft_eight_queens_puzzle.c)|
|[ex09](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY04/ex09)   |[The Eight Queens 2](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY04/ex09/README.md) |[ft_eight_queens_puzzle_2.c](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY04/ex09/ft_eight_queens_puzzle_2.c) |

## Exercise 00: ft_iterative_factorial
- Create an iterated function that returns a number. This number is the result of a factorial operation based on the number given as a parameter.
- If there's an error, the function should return 0.
- Here's how it should be prototyped:
```C
int	ft_iterative_factorial(int nb);
```
- Your function must return its result in less that two seconds.

## Exercise 01: ft_recursive_factorial
- Create a recursive functions that returns the factorial of the number given as a parameter.
- If there's an error, the function should return 0.
- Here's how it should be prototyped:
```C
int	ft_recursive_factorial(int nb);
```

## Exercise 02: ft_iterative_power
- Create an iterated function that returns the value of a power applied to a number. An power lower than 0 returns 0. Overflows don't have to be handled.
- Here's how it should be prototyped:
```C
int	ft_iterative_power(int nb, int power);
```

## Exercise 03: ft_recursive_power
- Create a recursive function that returns the value of a power applied to a number.
- Same conditions as before.
- Here's how it should be prototyped:
```C
int	ft_recursive_power(int nb, int power);
```

## Exercise 04: ft_fibonacci
- Create a function **ft_fibonacci** that returns the **n**th element of the Fibonacci sequence, the first element being at the 0 index. We'll consider that the Fibonacci sequence starts like this: 0, 1, 1, 2.
- Here's how it should be prototyped:
```C
int	ft_fibonacci(int index);
```
- Obviously, **ft_fibonacci** has to be recursive.
- If the index is less than 0, the function should return -1.

## Exercise 05: ft_sqrt
- Create a function that returns the square root of a number (if it exists), of 0 if the square root is an irrational number.
- Here's how it should be prototyped:
```C
int	ft_sqrt(int nb);
```

## Exercise 06: ft_is_prime
- Create a function that returns 1 if the number given as a parameter is a prime number, and 0 if it isn't.
- Here's how it should be prototyped:
```C
int	ft_is_prime(int nb);
```
- Your function must return its result in less than two seconds.
- **HINT**: 0 and 1 are not prime numbers.

## Exercise 07: ft_find_next_prime
- Create a function that returns the next prime number greater of equal to the number given as argument.
- Here's how it should be prototyped:
```C
int	ft_find_next_prime(int nb);
```
- Your function must return its result in less than two seconds.

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


