## Exercise

```
======================================./2-0-inter.txt=========================================
Assignment name  : inter
Expected files   : inter.c
Allowed functions: write
----------------------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.

The display will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Examples:

$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "rien" "cette phrase ne cache rien" | cat -e
rien$
$>./inter | cat -e
$
==============================================================================================
```

### Algorithm

- First we check if the number of input arguments are 3
- Then for every character in the first string.
	- We check if it's exist in in the first string.
		- ex: string = "Future", Char "r".
		- First we check if "r" exist in "Futu" 
	- If it already exist we go to the next character.
	- If not we check if that character exist in the second string.
	- If it does we print it.
	- If not we go to the next character in the second string.
- We print a new line.

