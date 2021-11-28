## Exercise

```
======================================./2-5-ft_strrev.txt=========================================
Assignment name  : ft_strrev
Expected files   : ft_strrev.c
Allowed functions: 
--------------------------------------------------------------------------------------------------

Write a function that reverses (in-place) a string.

It must return its parameter.

Your function must be declared as follows:

char    *ft_strrev(char *str);
==================================================================================================
```

## Algorithm

- First we get the index of the first and the last element of the given string.
- Then We go through a loop as long as the first index is less than the last index.
	- We assign the first char to a temporary variable.
	- Then we assign the last char to the first char.
	- Finally we assign the tmp variable to the last char.
	- Meanwhile decrementing the last index and incrementing the first one.
- Finally we return the address of the str.

