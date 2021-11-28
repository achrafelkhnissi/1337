# LIST OF DAY02 EXERCISES

|Exercise        |Description                    |Solution                     |
|-------------|-------------------------------|-----------------------------|
|[ex00](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/DAY02/ex00)         |[putchar](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/DAY02/ex00/README.md) |[ft_putchar.c](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/DAY02/ex00/ft_putchar.c)                |
|[ex01](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/DAY02/ex01)         |[print alphabet](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/DAY02/ex01/README.md)                  |[ft_print_alphabet.c](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/DAY02/ex01/ft_print_alphabet.c)|
|[ex02](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/DAY02/ex02)         |[print reverse alphabet](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/DAY02/ex02/README.md)             |[ft_print_reverse_alphabet](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/DAY02/ex02/ft_print_reverse_alphabet.c)|
|[ex03](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/DAY02/ex03)        |[print numbers](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/DAY02/ex03/README.md)  |[ft_print_numbers.c](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/DAY02/ex03/ft_print_numbers.c)|
|[ex04](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/DAY02/ex04)         |[is negative](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/DAY02/ex08/README.md)          |[ft_is_negative.c](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/DAY02/ex04/ft_isnegative.c)|
|[ex05](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/DAY02/ex05)         |[print comb](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/DAY02/ex05/README.md)              |[ft_print_comb.c](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/DAY02/ex05/ft_print_comb.c)|
|[ex06](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/DAY02/ex06)         |[print comb2](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/DAY02/ex06/README.md)          |[ft_print_comb2.c](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/DAY02/ex06/ft_print_comb2.c)|
|[ex07](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/DAY02/ex07)         |[put numbers](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/DAY02/ex07/README.md)              |[ft_putnbr.c](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/DAY02/ex07/ft_putnbr.c)|
|[ex08](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/DAY02/ex08)         |[print combn](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/DAY02/ex08/README.md)     |[ft_print_combn.c](https://github.com/achrafelkhnissi/1337/tree/master/Piscine-2021/DAYS/DAY02/ex08/ft_print_combn_v2.c)|

## EXERCISE 00
* Write a function that displays characters passed as parameter.
* This is how it should be prototyped:
```C
void	ft_putchar(char c);
```
* Files to turn in: ft_putchar.c
* Allowed function: write

## EXERCISE 01
* Create a function that displays the alphabet in lowercase, on a single line, by ascending order, starting from the letter 'a'.
* Here's how it should be prototyped:
```C
void	ft_print_alphabet(void);
```
* Files to turn in: ft_print_alphabet.c
* Allowed funcitons: ft_putchar

## EXERCISE 02
* Create a function that displays the alphabet in lowercase, on a single line, by descending order, starting from the letter 'z'.
* Here's how it should be prototyped:
```C
void	ft_print_reverse_alphabet(void);
```
* Files to turn in: fr_reverse_alphabet.c
* Allowed functions: ft_putchar

## EXERCISE 03
* Create a function that displays all digits, on a single line, by ascending order.
* Here's how it should be prototyped:
```C
void	ft_print_numbers(void);
```
* Files to turn in: ft_print_numbers.c
* Allowed functions: ft_putchar

## EXERCISE 04
* Create a function that displays 'N' or 'P' depending on the integer's sign entered as a parameter. If **n** is negative, display 'N', if **n** is positive or null, display 'P'.
* Here's how it should be prototyped:
```C
void	ft_is_negative(int n);
```
* Files to turn in: ft_is_negative.c
* Allowed funcitons: ft_putchar

## EXERCISE 05
* Create a function that displays all different combinations of three different digits in ascending order, listed by ascending order - yes, repetition is voluntary.
* Here's the intended output:
```
$>./a.out | cat -e
012, 013, 014, 015, 016, 017, 018, 019, 023, ..., 789$>
```
* 987 isn't there because 789 already is.
* 999 isn't there because digit 9 is present more than once.
* Here's how it should be prototyped:
```C
void	ft_print_comb(void);
```
+ Files to turn in: ft_print_comb.c
+ Allowed functions: ft_putchar

## EXERCISE 06
* Create a function that displays all different combinations of two digits between 00 and 99, listed by ascending order.
* Here's the expected output:
```
$>./a.out | cat -e
00 01, 00 02, 00 03, 00 04, 00 05, ..., 00 99, 01 02, ..., 97 99, 98 99$>
```
* Here's how it should be prototyped:
```C
void	ft_print_comb2(void);
```
+ Files to turn in: ft_print_comb2.c
+ Allowed functions: ft_putchar

## EXERCISE 07
* Create a function that displays the number entered as a parameter. The function has to be able to display all possible values within an int type variable.
* Here's how it should be prototyped:
```C
void	ft_putnbr(int nbr);
```
* For example:
	* ft_putnbr(1337) displays '1337'.
+ Files to turn in: ft_putnbr.c
+ Allowed functions: ft_putchar

## EXERCISE 08
* Create a function that displays all different combinations of **n** numbers by ascending order.
* **n** will be so that: 0 < n < 10.
* If **n** == 2, here's the expected output:
```
$>./a.out | cat -e
01, 02, 03, ..., 09, 12, ..., 79, 89$>
```
* Here's how it should be prototyped:
```C
void	ft_print_combn(int n);
```
+ Files to turn in: ft_print_combn.c
+ Allowed functions: ft_putchar


