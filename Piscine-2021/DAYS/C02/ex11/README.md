## Exercise 22: ft_putstr_non_printable
- Create a function that displays a string of characters onscreen. If this string contains characters that aren't printable, they'll have to be displayed in the shape of hexadecimals (lowercase), preceded by a "backslash".
- For example:
> Coucou\ntu vas bien ?
- The function should display:
> Coucou\0atu vas bien ?
- Here's how it should be prototyped:
```C
	void	ft_putstr_non_printable(char *str);
```

TODO:
1. scan text for none printable character.
2. get the integer value of the particular character.
3. convert the value to hex. (and from int to str)
4. replace the non-printable character with the converted value.\
	insert the converted hex string in the index of the non printable character 

note:
- we need a function to convert integer to a null terminated string. (including negative).


## IMPORTANT:
that's why you always need to understand the exercise the right way.\
because the simplest steps are:\
1. for every character in the given string print it if it's printable
2. if not then print the hex value of it after printing \\0.
