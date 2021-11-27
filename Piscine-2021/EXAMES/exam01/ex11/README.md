## Exercise

```
======================================./1-4-rotone.txt=========================================
Assignment name  : rotone
Expected files   : rotone.c
Allowed functions: write
-----------------------------------------------------------------------------------------------

Write a program that takes a string and displays it, replacing each of its
letters by the next one in alphabetical order.

'z' becomes 'a' and 'Z' becomes 'A'. Case remains unaffected.

The output will be followed by a \n.

If the number of arguments is not 1, the program displays \n.

Example:

$>./rotone "abc"
bcd
$>./rotone "Les stagiaires du staff ne sentent pas toujours tres bon." | cat -e
Mft tubhjbjsft ev tubgg of tfoufou qbt upvkpvst usft cpo.$
$>./rotone "AkjhZ zLKIJz , 23y " | cat -e
BlkiA aMLJKa , 23z $
$>./rotone | cat -e
$
$>
$>./rotone "" | cat -e
$
$>
===============================================================================================
```

### Algorithm

- First we check if the input arguments are 2
- If so. We check if the character is >= 'a' && <= 'z' (& uppercase as well)
	- If so we print the char + 1.
- If not, we check if the character is equal to 'z' upper and lower, if so we print 'a' or 'A'
- If not, we print the character as it is.

