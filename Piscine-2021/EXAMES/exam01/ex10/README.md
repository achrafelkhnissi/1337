## Exercise

```
======================================./1-3-rev_print.txt=========================================
Assignment name  : rev_print
Expected files   : rev_print.c
Allowed functions: write
--------------------------------------------------------------------------------------------------

Write a program that takes a string, and displays the string in reverse
followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./rev_print "zaz" | cat -e
zaz$
$> ./rev_print "dub0 a POIL" | cat -e
LIOP a 0bud$
$> ./rev_print | cat -e
$
==================================================================================================
```

### Algorithm

- First we check if the number of input arguments is 2
- If so. We get the length of the second argument.
- Note: the length of a string is also the index of the last element of that string.
- So we go through that string from the last element printing each character and decrementing the index variable.
- Finally we print a new line.

