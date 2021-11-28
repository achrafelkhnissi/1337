## Exercise 08: rb_insert

- Create a function `rb_insert` that adds a new data to the tree so that it continues to respect a red and black tree's restrictions. The argument `root` points to the tree's root node. Upon first call, it points to `NULL`. We'll also pass a comparison function similar to `strcmp` as argument.
- Here's how it should be prototyped:
```c
void rb_insert(struct s_rb_node **node, void *data, int (*cmpf)(void *, void *));
```

## Notes

- Check "rudimentary form of polymorphism in C"
- rb_btree rules (6 rules)
	- Every node is either red of black.
	- Root is always black. (if not we make it black)
	- New insertions are always red. (if the new insertion is root then we make it black)
	- Every possible path from root to leaf has the same number of black nodes.
	- No path can have two consecutive red nodes.
	- Nulls are black.
- If the tree violate the 6 rules, we have to fix it.
	- Balance:
		- if we have black aunt we rotate : bar
		- if we have red aunt we color-flip

```
	after rotation			after color-flip
	     black			      red
	    /     \			     /   \
	   red    red       		  black  black
```

## resources
- [Red/black Tree Visualization](https://www.cs.usfca.edu/~galles/visualization/RedBlack.html)
- [Set 1 - intro](https://www.geeksforgeeks.org/red-black-tree-set-1-introduction-2/)
- [Set 1 - insert](https://www.geeksforgeeks.org/red-black-tree-set-2-insert/)
- [red/black tree rules](https://www.youtube.com/watch?v=nMExd4DthdA&list=TLPQMDIwODIwMjHTAIZiojEtmA&index=2)
- [red/black tree examples of building a tree](https://www.youtube.com/watch?v=v6eDztNiJwo&list=TLPQMDIwODIwMjHTAIZiojEtmA&index=2)

