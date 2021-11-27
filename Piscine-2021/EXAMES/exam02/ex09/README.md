## Exercise

```
======================================./2-3-wdmatch.txt=========================================
Assignment name  : wdmatch
Expected files   : wdmatch.c
Allowed functions: write
------------------------------------------------------------------------------------------------

Write a program that takes two strings and checks whether it's possible to
write the first string with characters from the second string, while respecting
the order in which these characters appear in the second string.

If it's possible, the program displays the string, followed by a \n, otherwise
it simply displays a \n.

If the number of arguments is not 2, the program displays a \n.

Examples:

$>./wdmatch "faya" "fgvvfdxcacpolhyghbreda" | cat -e
faya$
$>./wdmatch "faya" "fgvvfdxcacpolhyghbred" | cat -e
$
$>./wdmatch "quarante deux" "qfqfsudf arzgsayns tsregfdgs sjytdekuoixq " | cat -e
quarante deux$
$>./wdmatch "error" rrerrrfiiljdfxjyuifrrvcoojh | cat -e
$
$>./wdmatch | cat -e
$
================================================================================================
```

## Algorithm

- First we check if the number of arguments is 3
- Then we get the length of the first string.
- After that we go through each character of the first string
	- We check if that character is exist in the second string.
		- if so we increment the variable found. then we break from the second loop.
		- else we go to the next character.
	- if not we go to the next character of the first string.
- Finally we check if the length of the first string is equal to found.
	- if so we print the first string.
- We print a new line.

