## Exercise 10: ft_list_foreach_if

- Create the function `ft_list_foreach_if` which applies a function given as argument to the information held in some links of the list. A reference information as well as a comparative function should allow us to select the right links of the list: those that are "equal" to the reference information.
- Here's how it should be prototyped:
```c
void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *), void *data_ref, int (*cmp)());
```
- Functions pointed by `f` and by `cmp` will be used as follows:
```c
(*f)(list_ptr->data);
(*cmp)(list_ptr->data, data_ref);
```

