## Exercise 07: ft_strncmp
- Reproduce the behavior of the function __strncmp__ (man strncmp).
- Here's how it should be prototyped:
```C
	int	ft_strncmp(char *s1, char *s2, unsigned int n);
```

## Understanding __strncmp__

### Description
The strncmp() function is used to compare two strings two strings str1 and str2. If two strings are same then strncmp() returns 0, otherwise, it returns a non-zero value.
The strncmp() function compares not more than n characters.  Because strncmp() is designed for comparing strings rather than binary data, characters that appear after a `\0' character are not compared.

### Return values
The strcmp() and strncmp() functions return an integer greater than, equal to, or less than 0, according as the string s1 is greater than, equal to, or less than the string s2.  The comparison is done using unsigned characters, so that '\200' is greater than '\0'.

| Value | Meaning |
|---|----|
| < 0| str1 < str2
| 0|str1 == str2
| > 0  | str1 > str2

## Solution
- declare an unsigned int variable and initialize it to 0 (index).
- check if the (n) == 0 is so we return (0).
- we go through a while loop as long as the nth character from str1 is == to the same nth character from str2. And al song as we didn't reach the end of the str1.
	- if (1) is less than (n - 1) (-1 because we start counting from 0)
		- we increment (1).
	- else we return (0), which means str1 and str2 are identical.
- Finally we return str1[i] - str2[i]. Which means strings are different and we return the different between them.

