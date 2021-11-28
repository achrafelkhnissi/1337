## Exercise 03: ft_strcpy

- Reproduce the behavior of the function __strcpy__ (man strcpy).
- Here's how it should be prototyped:
```C
   char		*ft_strcpy(char *dest, char *src);
```

## Understanding strcpy
Syntax: char \*strcpy (char \*destination, const char \*source);\

The strcpy() function is used to copy strings. It copies string pointed to by source into the destination. This function accepts two arguments of type pointer to char or array of characters and returns a pointer to the first string i.e destination. Notice that source is preceded by the const modifier because strcpy() function is not allowed to change the source string.

It is important to note that strcpy() function do not check whether the destination has enough size to store all the characters present in the source. It is the responsibility of the program to make sure that the destination array has enough space to accommodate all the characters of the source string.

Another important point to note about strcpy() is that you should never pass string literals as a first argument. For example:

```C
char ch_arr[] = "string array";

strcpy("destination string", c_arr); // wrong
```

Here you are trying to copy the contents of ch_arr to "destination string" which is a string literal. Since modifying a string literal causes undefined behaviour, calling strcpy() in this way may cause the program to crash.
