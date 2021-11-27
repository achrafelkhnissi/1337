## Exercise

```
======================================./2-5-ft_strcmp.txt=========================================
Assignment name  : ft_strcmp
Expected files   : ft_strcmp.c
Allowed functions: 
--------------------------------------------------------------------------------------------------

Reproduce the behavior of the function strcmp (man strcmp).

Your function must be declared as follows:

int    ft_strcmp(char *s1, char *s2);
==================================================================================================
```

### Algorithm

- We go through a loop as long as the 'n' character of the string 1 is equal to the character of string 2 of the same index. && make sure that character isn't '\0'
- Finally we return (s1 char index i - s2 char from of the same index)
