## Exercise 05: ft_param_to_tab
- Create a function that stores the program's arguments within an array of structure and that returns the address of that array's first box.
- All elements of the array must be processed, including __av[0]__.
- Here's how it should be prototyped:

```C
	struct s_stock_par *ft_param_to_tab(int ac, char **av);
```

- The structure array should be allocated and its last box shall contain 0 in its __str__ element to point out the end of the array.
- Allowed functions: ft_split_whitespaces, ft_show_tab, malloc
- The structure is defined in the __ft_stock_par.h__ file, like this

```C
typedef struct s_stock_par
{
	int	size_param;
	char	*str;
	char	*copy;
	char	**tab;
}	t_stock_par;
```

- __size_param__ being the length of the argument;
- __str__ being the address of the argument;
- __copy__ being the copy of the argument;
- __tab__ being the array returned by ft_split_whitespaces;
- We'll test your function with our __ft_split_whitespaces__ and our __ft_show_tab__ (next exercise). Take the appropriate measures for this to work!.


