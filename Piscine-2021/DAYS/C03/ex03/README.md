## Exercise 17: ft_strncat
- Reproduce the behavior of the function strncat (man strncat).
- Here's how it should be prototyped:
```C
	char	*ft_strncat(char *dest, char *src, int nb);
```

## Understanding strncat
### Description:
The strncat() function appends the first count characters of string2 to string1 and ends the resulting string with a null character (\0). If count is greater than the length of string2, the length of string2 is used in place of count.\
The strncat() function operates on null-ended strings. The string argument to the function should contain a null character (\0) marking the end of the string.

### Return value
The strncat() function returns a pointer to the joined string (string1).

