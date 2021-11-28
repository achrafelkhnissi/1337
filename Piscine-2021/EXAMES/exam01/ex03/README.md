## Exercise

```
======================================./1-0-search_and_replace.txt========================
Assignment name  : search_and_replace
Expected files   : search_and_replace.c
Allowed functions: write, exit
------------------------------------------------------------------------------------------

Write a program called search_and_replace that takes 3 arguments, the first 
arguments is a string in which to replace a letter (2nd argument) by
another one (3rd argument).

If the number of arguments is not 3, just display a newline.

If the second argument is not contained in the first one (the string)
then the program simply rewrites the string followed by a newline.

Examples:
$>./search_and_replace "Papache est un sabre" "a" "o"
Popoche est un sobre
$>./search_and_replace "zaz" "art" "zul" | cat -e
$
$>./search_and_replace "zaz" "r" "u" | cat -e
zaz$
$>./search_and_replace "jacob" "a" "b" "c" "e" | cat -e
$
$>./search_and_replace "ZoZ eT Dovid oiME le METol." "o" "a" | cat -e
ZaZ eT David aiME le METal.$
$>./search_and_replace "wNcOre Un ExEmPle Pas Facilw a Ecrirw " "w" "e" | cat -e
eNcOre Un ExEmPle Pas Facile a Ecrire $
==========================================================================================
```

### Algorithm

- We first check if the `argc == 4` and the length of `argv[2] == 1 && argv[3] == 1`
	- to make sure that the input is valid.
- If the input is valid we go through the input string `argv[1]` character by character
	- Then we check if the current character if equal to the character in `argv[2]`
		- If so. We print the character in `argv[3]`
	- Else we print the character.
- Finally we print a new line.

