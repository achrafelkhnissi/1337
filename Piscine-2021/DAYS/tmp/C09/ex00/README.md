## Exercise 00: ft_create_elem

- Create the function `ft_create_elem` which creates a new element of `t_list` type.
- It should assign `data` to the given argument and `next` to `NULL`.
- Here's how it should be prototyped:
```c
t_list	*ft_create_elem(void *data)
```

### Solution
It's pretty straight forward:
1. First we create a new element of `t_list` type then allocate memory for it.
2. We check if the return value of `malloc` is `NULL`, if so we return `NULL`.
3. If not we assign `data` to the given argument and `next` to `NULL`.
4. Finally we return the newly created element.
