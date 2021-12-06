## Exercise 01: btree_apply_prefix

- Create a function `btree_apply_prefix` which applies the function given as argument to the `item` of each node, using `prefix traversal` to search the tree.
- Here's how it should be prototyped:
```c
void	btree_apply_prefix(t_btree *root, void (*applyf)(void *));
```
