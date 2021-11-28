# LIST OF DAY03 EXERCISES

|Exercise        |Description                    |Solution                     |
|-------------|-------------------------------|-----------------------------|
|[ex00](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY03/ex00)      |[ft_ft](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY03/ex00/README.d)          |[ft_ft.c](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY03/ex00/ft_ft.c) |
|[ex01](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY03/ex01)     |[ft_ultimate_ft](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY03/ex01/README.md)  |[ft_ultimate_ft.c](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY03/ex01/ft_ultimate_ft.c)  |
|[ex02](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY03/ex02)   |[ft_swap](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY03/ex02/README.md)           |[ft_swap.c](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY03/ex02/ft_swap.c)         |
|[ex03](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY03/ex03)   |[ft_div_mod](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY03/ex03/README.md)           |[ft_div_mod.c](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY03/ex03/ft_div_mod.c)      |
|[ex04](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY03/ex04)   |[ft_ultimate_div_mod](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY03/ex04/README.md)        |[ft_ultimate_div_mod.c](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY03/ex04/ft_ultimate_div_mod.c)  |
|[ex05](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY03/ex05)   |[ft_pustr](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY03/ex05/README.md)       |[ft_putstr.c](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY03/ex05/ft_putstr.c)       |
|[ex06](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY03/ex06)   |[ft_strlen](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY03/ex06/README.md)           |[ft_strlen.c](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY03/ex06/ft_strlen.c) |
|[ex07](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY03/ex07)   |[ft_strrev](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY03/ex07/README.md)        |[ft_strrev.c](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY03/ex07/ft_strrev.c)       |
|[ex08](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY03/ex08)   |[ft_atoi](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY03/ex08/README.md)     |[ft_atoi.c](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY03/ex08/ft_atoi.c)|
|[ex09](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY03/ex09)   |[ft_sort_integer_table](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY03/ex09/README.md) |[ft_sort_integer_table.c](https://github.com/achrafelkhnissi/1337/blob/master/Piscine-2021/DAYS/DAY03/ex09/ft_sort_integer_table.c) |


## Exercise 00: ft_ft
+ Create a function that takes a pointer to int as parameter, and sets the value "1337" to that int.
+ Here's how it should be prototyped:
```C
void	ft_ft(int *nbr);
```
+ Files to turn in: ft_ft.c
+ Allowed functions: Nothing

## Exercise 01: ft_ultimate_ft
+ Create a function that takes a pointer to pointer to pointer to pointer to pointer to pointer to pointer to pointer to pointer to int as a parameter and sets the value "1337" to that int.
+ Here's how it should be prototyped:
```C
void	ft_ultimate_ft(int *********nbr);
```
+ Files to turn in: ft_ultimate_ft.c
+ Allowed functions: Nothing

## Exercise 02: ft_swap
+ Create a function that swaps the value of two integers whose addresses are entered as parameters.
+ Here’s how it should be prototyped:
```C
void	ft_swap(int *a, int *b);
```
+ Files to turn in: ft_swap.c
+ Allowed functions: Nothing

## Exercise 03: ft_div_mod
+ Create a function **ft_div_mod** prototyped like this:
```C
void	ft_div_mod(int a, int b, int *div, int *mod);
```
+ This function divides parameters a by b and stores the result in the int pointed by div. It also stores the remainder of the division of a by b in the int pointed by mod.
+ Files to turn in: ft_div_mod.c
+ Allowed functions: Nothing

## Exercise 04: ft_ultimate_div_mod
+ Create a function **ft_ultimate_div_mod** with the following prototype:
```C
void	ft_ultimate_div_mod(int *a, int *b);
```
+ This function divides parameters a by b. The result of this division is stored in the int pointed by a. The remainder of the division is stored in the int pointed by b.
+ Files to turn in: ft_ultimate_div_mod.c
+ Allowed functions: Nothing

## Exercise 05: ft_putstr
+ Create a function that display a string of characters on the standard output.
+ Here's how it should be prototyped:
```C
void	ft_putstr(char *str);
```
+ Files to turn in: ft_putstr.c
+ Allowed functions: ft_putchar

## Exercise 06: ft_strlen
+ Create a function that counts and returns the number of characters in a string.
+ Here's how it should be prototyped:
```C
int	ft_strlen(char *str);
```
+ Files to turn in: ft_strlen
+ Allowed functions: Nothing

## Exercise 07: ft_strrev
+ Create a function that reverse the order of characters in a string.
+ It has to return str.
+ Here's how it should be prototyped:
```C
char	*ft_strrev(char *str);
```
+ Example:
```
	a     => a
	ab    => ba
	abcde => edcba
```
+ Files to turn in: ft_strrev.c
+ Allowed functions: Nothing

## Exercise 08: ft_atoi
+ Reproduce the behavior of the function atoi (man atoi).
+ Here's how it should be prototyped:
```C
int	ft_atoi(char *str);
```
+ Files to turn in: ft_atoi.c
+ Allowed functions: Nothing

## Exercise 09: ft_sort_integer_table
+ Create a function which sorts an array (table) of integers by ascending order.
+ The arguments are a pointer to int and the number of ints in the array.
+ Here's how it should be prototyped:
```C
void	ft_sort_integer_table(int *tab, int size);
```
+ Files to turn in: ft_sort_integer_table.c
+ Allowed functions: Nothing



