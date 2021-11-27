## Exercise

```
======================================./1-0-ft_strcpy.txt=================================
Assignment name  : ft_strcpy
Expected files   : ft_strcpy.c
Allowed functions: 
------------------------------------------------------------------------------------------

Reproduce the behavior of the function strcpy (man strcpy).

Your function must be declared as follows:

char    *ft_strcpy(char *s1, char *s2);
==========================================================================================
```

### Algorithm

- Go through each character of `s1` and assign it to `s2`
	- (as long as that character isn't `\0` the end of the string.)
- Add `\0` to the end of the `s2` string.

