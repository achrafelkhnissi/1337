## Exercise 04: btree_insert_data

- Create a function `btree_insert_data` which inserts the element `item` into a tree. The tree passed as argument will be stored: for each `node` all lower elements are located on the left side and all higher or equal elements on the right. We'll also pass a comparison function similar to `strcmp` as argument.
- The root parameter points to the root node of the tree. First time called, it should point to `NULL`.
- Here's how it should be prototyped:
```c
void	btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *));
```

