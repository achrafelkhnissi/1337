## Exercise

```
======================================./2-0-ft_atoi.txt=========================================
Assignment name  : ft_atoi
Expected files   : ft_atoi.c
Allowed functions: None
------------------------------------------------------------------------------------------------

Write a function that converts the string argument str to an integer (type int)
and returns it.

It works much like the standard atoi(const char *str) function, see the man.

Your function must be declared as follows:

int	ft_atoi(const char *str);
================================================================================================
```

### Algorithm

- First we declare a sign variable to hold the sign of the input.
- Then we go through each character in the input string incrementing the index as long as the current character is a whitespace.
- After we reach a character that isn't a whitespace.
	- We check if that character is '-' if so we assign the sign variable to -1.
	- If not. We check if that character is '+'. If so we increment the index by 1.
- Then we go through each character as long as that character is representing a number.
	- Then we get the numeric value of that character using (- '0')
	- Then add that value to the (nb \* 10) and assign the result to nb.
	- finally we increment the index variable.
- And finally we return the nb \* sign.

