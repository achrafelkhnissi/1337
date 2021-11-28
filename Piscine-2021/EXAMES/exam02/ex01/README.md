## Exercise

```
======================================./2-0-ft_strdup.txt=========================================
Assignment name  : ft_strdup
Expected files   : ft_strdup.c
Allowed functions: malloc
--------------------------------------------------------------------------------------------------

Reproduce the behavior of the function strdup (man strdup).

Your function must be declared as follows:

char    *ft_strdup(char *src);
==================================================================================================
```

### Algorithm

- First we declare a (char \*) to store the copy of the input string.
- Then we get the length of the string and assign it to a variable index.
- After that we use malloc to allocate memory for the variable copy using the length of the input string * the sizeof(char) + 1 (the 1 of for '\0')
- Then we check the return value of malloc if null or not.
	- if NULL we return NULL.
- Then we go through each character of the given string and copy it to the variable copy.
- We assign '\0' to the last element of the string indicating the end of the string.
- Finally we return the address of the copy.


