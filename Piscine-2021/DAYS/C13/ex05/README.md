## Exercise 05: btree_search_item

- Create a function `btree_search_item` which returns the first element related to the reference data given ad argument. The tree should be browsed using `infix traversal`. If the element isn't found, the function should return `NULL`.
- Here's how it should be prototyped:
```c
void	*btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *));
```
