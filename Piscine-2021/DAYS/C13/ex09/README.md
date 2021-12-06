## Exercise 09: rb_remove

- Create a function `rb_remove` which removes a data from the tree so that it continues to respect a red and black tree's restrictions. The argument `root` points to the tree's root node. We'll also pass a comparison function similar to `strcmp` as argument, as well as a pointer to function `freef` which will be called, with the element of the tree to be deleted, as argument.

- Here's how it should be prototyped: 
```c
void rb_remove(struct s_rb_node **root, void *data, int (*cmpf)(void *, void *), void (*freef)(void *));
```

