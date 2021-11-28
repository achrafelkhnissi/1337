## Exercise 16: ft_strcat
- Reproduce the behavior of the function __strcat__ (man strcat).
- Here's how it should be prototyped:
```C
	char	*ft_strcat(char *dest, char *src);
```

## Understanding strcat
### Description:
The strcat() function concatenates string2 to string1 and ends the resulting string with the null character.\
The strcat() function operates on null-ended strings. The string arguments to the function should contain a null character (\0) that marks the end of the string. No length checking is performed. You should not use a literal string for a string1 value, although string2 may be a literal string.\
If the storage of string1 overlaps the storage of string2, the behavior is undefined.

### Return value
The strcat() function returns a pointer to the concatenated string (string1).

