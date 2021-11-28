## Exercise

```
======================================./2-1-alpha_mirror.txt=========================================
Assignment name  : alpha_mirror
Expected files   : alpha_mirror.c
Allowed functions: write
-----------------------------------------------------------------------------------------------------

Write a program called alpha_mirror that takes a string and displays this string
after replacing each alphabetical character by the opposite alphabetical
character, followed by a newline.

'a' becomes 'z', 'Z' becomes 'A'
'd' becomes 'w', 'M' becomes 'N'

and so on.

Case is not changed.

If the number of arguments is not 1, display only a newline.

Examples:

$>./alpha_mirror "abc"
zyx
$>./alpha_mirror "My horse is Amazing." | cat -e
Nb slihv rh Znzarmt.$
$>./alpha_mirror | cat -e
$
$>
=====================================================================================================
```

### Solution

- If the letter is lowercase:
	- print ('a' - letter + 'z')
- If the letter is uppercase:
	- print ('A' - letter + 'Z')

#### OR

- if the letter is lowercase:
	- print ('m' - (letter - 'n'))
- if the letter is uppercase:
	- print ('M' - (letter - 'N'))

