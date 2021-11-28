## Exercise 06: ft_strcmp
- Reproduce the behavior of the function strcmp (man strcmp).
- Here's how it should be prototyped:
```C
	int	ft_strcmp(char *s1, char *s2);
```

## Understanding strcmp

### Description
The strcmp() function is used to compare two strings two strings str1 and str2. If two strings are same then strcmp() returns 0, otherwise, it returns a non-zero value.

### Return values
The strcmp() and strncmp() functions return an integer greater than, equal to, or less than 0, according as the string s1 is greater than, equal to, or less than the string s2.  The comparison is done using unsigned characters, so that `\200' is greater than `\0'.

| Value | Meaning |
|---|----|
| < 0| str1 < str2
| 0|str1 == str2
| > 0  | str1 > str2

### More
[Detailed description](https://overiq.com/c-programming-101/the-strcmp-function-in-c/)
