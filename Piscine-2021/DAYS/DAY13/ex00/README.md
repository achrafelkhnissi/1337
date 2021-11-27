## Exercise 00: btree_create_node

- Create the function `btree_create_node` which allocates a new element. It should initialise its `item` to the argument's value, and all other elements to 0.
- The created node's address is returned.
- Here's how it should be prototyped:
```c
b_tree *btree_create_node(void *item);
```

