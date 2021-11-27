## Exercise

```
======================================./1-2-first_word.txt================================
Assignment name  : first_word
Expected files   : first_word.c
Allowed functions: write
------------------------------------------------------------------------------------------

Write a program that takes a string and displays its first word, followed by a
newline.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or if there are no words, simply display
a newline.

Examples:

$> ./first_word "FOR PONY" | cat -e
FOR$
$> ./first_word "this        ...       is sparta, then again, maybe    not" | cat -e
this$
$> ./first_word "   " | cat -e
$
$> ./first_word "a" "b" | cat -e
$
$> ./first_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>
==========================================================================================
```

### Algorithm

- First we check if the input has 2 arguments
- If true. We go through each character
	- We check if that character is not a space and the next character is also not a space.
	- If True we enter a loop as long as the current character isn't a space we print it
		- Then we break when we reach a space.
	- We increment the index. (means that the current char is space.)
- Finally we print a new line.

