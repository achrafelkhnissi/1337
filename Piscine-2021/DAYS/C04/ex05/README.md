## Exercise 05: ft_atoi_base
- Create a function that returns a number. This number is shaped as a string of characters.
- The string of characters reveals the number in a specific base, given as a second paramter.
- The function must handle negative numbers.
- The function must handle signs like __man atoi__.
- If There's an invalid argument, the function should return 0. Example of invalid arguments:
	- str is an empty string;
	- the base is empty or size of 1;
	- str contains characters that aren't part of the base, or aren't + or - ;
	- the base contains the same character twice;
	- the base contains + or -;
	- etc.
- Here's how it should be prototyped:
```C
	int	ft_atoi_base(char *str, char *base);
```


