## Exercise

```
======================================./1-0-repeat_alpha.txt==============================
Assignment name  : repeat_alpha
Expected files   : repeat_alpha.c
Allowed functions: write
------------------------------------------------------------------------------------------

Write a program called repeat_alpha that takes a string and display it
repeating each alphabetical character as many times as its alphabetical index,
followed by a newline.

'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...

Case remains unchanged.

If the number of arguments is not 1, just display a newline.

Examples:

$>./repeat_alpha "abc"
abbccc
$>./repeat_alpha "Alex." | cat -e
Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
$>./repeat_alpha 'abacadaba 42!' | cat -e
abbacccaddddabba 42!$
$>./repeat_alpha | cat -e
$
$>
$>./repeat_alpha "" | cat -e
$
$>
==========================================================================================
```

## Algorithm

- First check if the `argc` is 2
- If so. Go through each character of the second argument `argv[1]` because the first argument is the name of the program.
- As long as the character isn't `\0` we check if the character is an alphabetical character.
- If so we get the index of that character and store it in a variable.
	- Then we go through that index as long printing the same character and decrementing the index by 1.
- If not we print the character.
- Finally we print a new line.

#### get_index funciton
- We first declare two variables one to hold the index and we assign 'a' to the second.
- We check if the character is upper chase. If so we convert (either that character to lowcase) or our variable to upper case.
- Then as long as our letter isn't not equal to the input character.
	- We increment both out letter and the index.
- Finally we return the index + 1 (because the first alphabet is index 1 not 0).

