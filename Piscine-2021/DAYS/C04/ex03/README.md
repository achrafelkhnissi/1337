## Exercise 03: ft_atoi
+ Reproduce the behavior of the function atoi (man atoi).
+ Here's how it should be prototyped:
```C
int	ft_atoi(char *str);
```
+ Files to turn in: ft_atoi.c
+ Allowed functions: Nothing

## [atoi  description](https://www.ibm.com/docs/en/i/7.4?topic=functions-atoi-convert-character-string-integer)
+ The atoi() function converts a character string to an integer value. The input string is a sequence of characters that can be interpreted as a numeric value of the specified return type. The function stops reading the input string at the first character that it cannot recognize as part of a number. This character can be the null character that ends the string.
* The atoi() function does not recognize decimal points or exponents. The string argument for this function has the form:\
	`whitespaces +/- digits`
* whitespace characters are space `(' ')`, tab `('\t')`, carriage return `('\r')`, newline `('\n')`, vertical tab `('\v')` and formfeed `('\f')`.
* where whitespace consists of the same characters for which the isspace() function is true, such as spaces and tabs. The atoi() function ignores leading white-space characters. The value digits represents one or more decimal digits.
* Return value: The atoi() function returns an int value that is produced by interpreting the input characters as a number. The return value is 0 if the function cannot convert the input to a value of that type. The return value is undefined in the case of an overflow.

## Notes
- Using (\*str++) instead of "**i**" won't work! it's gonna work just for the first time.
	- \*str++: pointer arithmetic.
	- i: using index.
