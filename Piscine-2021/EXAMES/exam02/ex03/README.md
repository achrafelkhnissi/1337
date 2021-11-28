## Exercise

```
======================================./2-0-last_word.txt=========================================
Assignment name  : last_word
Expected files   : last_word.c
Allowed functions: write
--------------------------------------------------------------------------------------------------

Write a program that takes a string and displays its last word followed by a \n.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or there are no words, display a newline.

Example:

$> ./last_word "FOR PONY" | cat -e
PONY$
$> ./last_word "this        ...       is sparta, then again, maybe    not" | cat -e
not$
$> ./last_word "   " | cat -e
$
$> ./last_word "a" "b" | cat -e
$
$> ./last_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>
==================================================================================================
```

### Algorithm

- First we check if the input arguments are 2.
- If True. We get the index of the last word.
- Then we go through the last word as long as it's alphabetical and the index isn't not 0.
	- We print that word.
- Finally we print a new line.

#### Getting the index of the last word
- First we get the length of the string (so we can start from the last character)
- First we check if the last character is an alphabetical character && if the character before it is a space, if so we decrement the index.
- We go through each character decrementing the index as long as that character is a space character and the index is not 0.
	- If we reach a character that isn't a space we check if the next character is a space.
		- if so we decrement the index one more time so we don't break from the loop.
- Finally we know that we reached a world.
	- So we go through each character backward and decrement the index as long as it's not a space
	- and the index is not 0.
- We return the index.


