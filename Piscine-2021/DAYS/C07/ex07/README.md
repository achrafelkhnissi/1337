## Exercise 07: ft_split
- Create a function that split a string of character depending on another string of characters.
- You'll have to use each character from the string __charset__ as a separator.
- The function returns an array where each box contains the address of a string wrapped between two separators. The last element of the array should equal to 0 to indicate the end of the array.
- There cannot be any empty strings in your array. Draw your conclusions accordingly.
- The string given as argument won't be modifiable.
- Here's how it should be prototyped:
```C
	char **ft_split(char *str, char *charset);
```
- Allowed functions: malloc
