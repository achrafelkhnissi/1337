# Exercise 08: ft_advanced_sort_wordtab
- Create the function `ft_advanced_sort_wordtab` which sorts, depending on the return of the function given as argument, words obtained with `ft_split_whitespaces`.
- The sorting will be performed by exchanging the array’s pointers.
- Here’s how it should be prototyped:

```c
void	ft_advanced_sort_wordtab(char **tab, int(*cmp)(char *, char *));
```

- Hint: Calling `ft_advanced_sort_wordtab()` with `ft_strcmp` as a second argument will return the same result as `ft_sort_wordtab()`.
