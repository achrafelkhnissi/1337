## Exercise 04: ft_putnbr_base
- Create a function that displays a number in a base system onscreen.
- This number is given in the shape of an int, and the radix in the shape of a string of characters.
- The base-system contains all useable symbols to display that number:
	- 0123456789 is the commonly used base system to represent decimal numbers;
	- 01 is a binary base system;
	- 0123456789ABCDEF an hexadecimal base system;
	- poneyvif is an octal base system.
- The function must handle negative numbers.
- If there's an invalid argument, nothing should be displayed. Example of invalid arguments:
	- base is empty or size of 1;
	- base contains the same character twice;
	- base contains + or -;
	- etc.
- Here's how it should be prototyped:
```C
	void	ft_putnbr_base(int nbr, char *base);
```

## Solution
1. ft_putnbr_base function
	- declare a function __nbase__ to hold to return value of the "check_base" function.
	- if __nbase__ is greater or equal to 2 and less or equal to 16 (means in the range of the different bases)
		- if nbr is negative we print '-' and turn the number positive (same as putnbr).
		- if number is greater or equal to __nbase__ we call the __ft_putnbr_base__ function recursively (same as putnbr)
		- print base[nbr % base];

2. check_base function
	- declare the different bases.
	- we compare the input base we the bases that we declared.
	- if it is equal to one of those we return the length of it
	- if not we return 0

### Convert base 10 (decimal) to any base

ex: base 16 (hex)

1. 1337 / 16 = 83, r 9
2. 83 / 16 = 5, r 3
3. 5 / 16 = 0, r 5

result = 539.

decimal 1337 = hex 539

### Convert any base to base 10 (decimal)

n = number
bn = base of number
x = *
d++ = next digit

1. start from index 0 or for exampe 1337 we start from 7 to 1.
2. result = digit[d++] + nxx(bn++)
3. we increment bn till digit == 0
4. then the result is the base 10 value of the given number.

example: 
number = 0x789 of base 16

1. (9 * 16xx0) = 9
2. 9 + (8 * 16xx1) = 137
3. 137 + (7 * 16xx2) = 1929

or 
1. (7 * 16xx2) = 1792
2. 1792 + (8 * 16xx1) = 1920
3. 1920 + (9 * 16xx0) = 1929 
