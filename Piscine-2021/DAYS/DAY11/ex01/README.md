## Exercise 01: ft_list_push_back

- Create a function `ft_list_push_back` which adds a new element of `t_list` type at the end of the list.
- It should assign `data` to the given argument.
- If necessary, it'll update the pointer at the beginning of the list.
- Here's how it should be prototyped:
```c
void	ft_list_push_back(t_list **begin_list, void *data);
```

## Solution
1. First we create a new element of type `t_list`.
2. Then we check if `*begin_list` is null or not.
	- if it is not `NULL` we know that the list isn't empty.
	- so we assign `*begin_list` to the newly created element.
	- then we go through the list till we reach the last element.
	- then we create a new element passing the argument `data` and assign the address of that element to the end of the list (aka `next` of the last element).
3. If `*begin_list` is `NULL` then we know that the list is empty so we create a new element and assign in to it.

### note
- why passing `**begin_list` instead of `*begin_list`?
	- `**begin_list` means that we are expecting the address of the liked list, so we can directly modify it inside of our function without the need `return` anything.
	- it is like passing by reference and passing by value.
	- check the results of [p1_vs_p2](https://github.com/achrafelkhnissi/CS/blob/master/1337/DAYS/DAY11/ex00/test/1p_vs_2p.c)
	- & check [stackoverflow](https://stackoverflow.com/questions/7271647/what-is-the-reason-for-using-a-double-pointer-when-adding-a-node-in-a-linked-lis)
	- [Another source](https://www.youtube.com/watch?v=QH64qSW7wM8)
