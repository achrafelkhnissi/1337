## Exercise 12: ft_list_remove_if

- Create the function `ft_list_remove_if` which erases of the list elements, whose data is "equal" to the reference data.
- Here's how it should be prototyped:
```c
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());
```

### Solution
1. We declare the `prev` pointer to hold the previous element in the linked list and assign it to `NULL`.
2. We go through the linked list as long as `head` isn't `NULL`
3. We check if the current head's data is equal to the ref data.
	- If true:
		- We check if the current head is the begining of the list
			- If true we assign the beginning of the list to the next node.
			- Else we assign the prev->next to head->next
		- Then we assign head to tmp;
		- And head->next to head;
		- Finally we free tmp;
	- If false:
		- We assign head to prev;
		- and head->next to head;
