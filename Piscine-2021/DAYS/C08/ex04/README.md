## Exercise 04: ft_strs_to_tab 
- Create a function that takes an array of string as argument and the size of this array.
- Here's how it should be prototyped:

```C
	struct s_stock_par *ft_strs_to_tab(int ac, char **av);
```
- It will transform each element of av into a structure.
- The structure is defined in the __ft_stock_par.h__ file that we will provided, 

```C
typedef struct s_stock_par
{
	int		size;
	char	*str;
	char	*copy;
}	t_stock_par;
```
- __size__ being the length of the string;
- __str__ being the string; 
- __copy__ being the copy of the string;

- It should keep the order of av.
- The return array should allocated in memory and its last element's __str__ set to 0, this will mark the end of the array.
- It should return __NULL__ pointer if an error occurs.
