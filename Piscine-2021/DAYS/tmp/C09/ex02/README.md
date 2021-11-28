## Exercise 02: ft_list_push_front

- Create the function `ft_list_push_front` which adds a new element of type `t_list` to the beginning of the list.
- It should assign `data` to the given argument.
- If necessary, it'll update the pointer at the beginning of the list.
- Here's how it should be prototyped:
```c
void	ft_list_push_front(t_list **begin_list, void *data);
```

## Solution

1. First we create an element.
2. Then we check if the input linked list is empty or not.
3. If it isn't empty we call the function `create_elem` an assign the return value of the element that we previously created.
	- Then we assign the address head of the linked list to `next` of element.
	- New element is the start of the linked list but `*begin_list` still holds its value.
	- So we rewrite `*begin_list` and assign the address of `element` to it.
4. If the linked list is empty we create a new element and assign it to it.

