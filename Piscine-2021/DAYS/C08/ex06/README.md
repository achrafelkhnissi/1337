## Exercise 06: ft_show_tab
- Create a function that displays the content of the array created by the previous function.
- Here's how it should be prototyped:
```C
void	ft_show_tab(struct s_stock_par *par);
```
- The structure is defined in the __ft_stock_par.h__ file, like this:
```C
typedef struct s_stock_par
{
	int	size_param;
	char	*str;
	char	*copy;
	char	**tab;
}	t_stock_par;
```
- For each box, we'll display (one element per line):
	- the argument
	- the size
	- each word (one per line)
- We'll test your function with our __ft_param_to_tab__ (previous exercise). Take the appropriate measures for this to work!
- Allowed functions: ft_putchar
