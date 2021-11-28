## Exercise

```
======================================./0-0-maff_alpha.txt================================
Assignment name  : maff_alpha
Expected files   : maff_alpha.c
Allowed functions: write
------------------------------------------------------------------------------------------

Write a program that displays the alphabet, with even letters in uppercase, and
odd letters in lowercase, followed by a newline.

Example:

$> ./maff_alpha | cat -e
aBcDeFgHiJkLmNoPqRsTuVwXyZ$
==========================================================================================
```

### Algorithm

- Assign a variable to a lower case 'a'.
- For every letter in the alphabet check if the letter is even or odd ('letter' % 2).
- If even print it in upper case ('letter' - 32).
- Else print it as it is. 
