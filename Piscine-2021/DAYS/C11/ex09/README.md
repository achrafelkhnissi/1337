## Exercise 09: ft_list_foreach

- Create the function `ft_list_foreach` which applies a function given as argument to the information within each of the list's links.
- Here's how it should be prototyped:
```c
void	ft_list_foreach(t_list *begin_list, void (*f)(void *));
```
- The function pointed by `f` will be used as follows:
```c
(*f)(list_ptr->data)
```
