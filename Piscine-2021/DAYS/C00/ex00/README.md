## EXERCISE 00
* Write a function that displays characters passed as parameter.
* This is how it should be prototyped:
```C
void	ft_putchar(char c);
```
* Files to turn in: ft_putchar.c
* Allowed function: write

### write()
- write(2): the write function takes 3 parameters

	I. file descriptor\
	II. address to a buffer\
	III. count

	- 1. There is 3 types of file descriptor:
		* 0 standart input.
		* 1 standard output.
		* 2 standart error.	
	- 2. Address in memory that points to a string (if we write the string directly, the compiler will find a place in memory for it and place the address of it in the second parameter).
	- 3. The length: number of bytes to print

