## Exercise 02: btree_apply_infix

- Create a function `btree_apply_infix` which applies the function given as argument to the `item` of each node, using `infix traversal` to search the tree.
- Here's how it should be prototyped:
```c
void	btree_apply_infix(t_btree *root, void (*applyf)(void *));
```
