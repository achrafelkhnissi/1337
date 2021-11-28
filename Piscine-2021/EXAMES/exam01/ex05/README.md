## Exercise

```
======================================./1-1-rot_13.txt====================================
Assignment name  : rot_13
Expected files   : rot_13.c
Allowed functions: write
------------------------------------------------------------------------------------------

Write a program that takes a string and displays it, replacing each of its
letters by the letter 13 spaces ahead in alphabetical order.

'z' becomes 'm' and 'Z' becomes 'M'. Case remains unaffected.

The output will be followed by a newline.

If the number of arguments is not 1, the program displays a newline.

Example:

$>./rot_13 "abc"
nop
$>./rot_13 "My horse is Amazing." | cat -e
Zl ubefr vf Nznmvat.$
$>./rot_13 "AkjhZ zLKIJz , 23y " | cat -e
NxwuM mYXVWm , 23l $
$>./rot_13 | cat -e
$
$>
$>./rot_13 "" | cat -e
$
$>
==========================================================================================
```

### Algorithm

- There's 26 letters in the alphabet.
- Then 26 / 2 = 13
- Which is the number of the assignment
- Therefore we split the alphabet into 2
- If the input char is in the first half we increment it by 13.
- if the input char is in the second half, we decrement it by 13.
