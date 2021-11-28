## Exercise 03: btree_apply_suffix

- Create a function `btree_apply_suffix` which applies the function given as argument to the `item` of each node, using `suffix traversal` to search the tree.
- Here's how it should be prototyped:
```c
void	btree_apply_suffix(t_btree *root, void (*applyf)(void *));
```
