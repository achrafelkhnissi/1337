## Exercise

```
======================================./2-0-union.txt=========================================
Assignment name  : union
Expected files   : union.c
Allowed functions: write
----------------------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.

The display will be in the order characters appear in the command line, and
will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Example:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>
==============================================================================================
```

### Algorithm

- First we check if there is 3 arguments.
- If so. We go through each character of the first string
	- Checking if that character exists in range of the first character to the current character - 1.
	- if it doesn't exist we print it.
	- and we increment the index variable if the character already exist.
- Then we go through each character of the second string.
	- Checking if that character exist in the range of the first character to the current character - 1 (previous character to the current) 
	- If it doesn't exit..
		- We check if it does exist in the first string
			- and if it doesn't exist also we print it.
	- else we increment the index varaible.
- Finally we print a new line.

