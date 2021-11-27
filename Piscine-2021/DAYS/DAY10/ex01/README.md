# Exercise 01: ft_foreach
- Create the function `ft_foreach` which, for a given ints array, applies a function on all elements of the array. This function will be applied following the array's order.
- Here's how the function should be prototyped:

```C
void	ft_foreach(int *tab, int length, void(*f)(int));
```

- For example, the function `ft_foreach` could be called as following in order to display all ints of the array:

```c
ft_foreach(tab, 1337, &ft_putnbr);
```

