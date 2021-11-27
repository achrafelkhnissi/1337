# LIST OF DAY13 EXERCISES

|Exercise        |Description                    |Solution                     |
|-------------|-------------------------------|-----------------------------|
|[ex00](https://github.com/achrafelkhnissi/CS/blob/master/1337/DAYS/DAY13/ex00)      |[btree create node](https://github.com/achrafelkhnissi/CS/blob/master/1337/DAYS/DAY13/ex00/README.md)          |[btree_create_node.c](https://github.com/achrafelkhnissi/CS/blob/master/1337/DAYS/DAY13/ex00/btree_create_node.c) |
|[ex01](https://github.com/achrafelkhnissi/CS/blob/master/1337/DAYS/DAY13/ex01)     |[btree apply prefix](https://github.com/achrafelkhnissi/CS/blob/master/1337/DAYS/DAY13/ex01/README.md)  |[btree_apply_prefix.c](https://github.com/achrafelkhnissi/CS/blob/master/1337/DAYS/DAY13/ex01/btree_apply_prefix.c)  |
|[ex02](https://github.com/achrafelkhnissi/CS/blob/master/1337/DAYS/DAY13/ex02)   |[btree apply infix](https://github.com/achrafelkhnissi/CS/blob/master/1337/DAYS/DAY13/ex02/README.md)           |[btree_apply_infix.c](https://github.com/achrafelkhnissi/CS/blob/master/1337/DAYS/DAY13/ex02/btree_apply_infix.c)         |
|[ex03](https://github.com/achrafelkhnissi/CS/blob/master/1337/DAYS/DAY13/ex03)   |[btree_apply_suffix](https://github.com/achrafelkhnissi/CS/blob/master/1337/DAYS/DAY13/ex03/README.md)           |[btree_apply_suffix.c](https://github.com/achrafelkhnissi/CS/blob/master/1337/DAYS/DAY13/ex03/btree_apply_suffix.c)      |
|[ex04](https://github.com/achrafelkhnissi/CS/blob/master/1337/DAYS/DAY13/ex04)   |[btree insert data](https://github.com/achrafelkhnissi/CS/blob/master/1337/DAYS/DAY13/ex04/README.md)        |[btree_insert_data.c](https://github.com/achrafelkhnissi/CS/blob/master/1337/DAYS/DAY13/ex04/btree_insert_data.c)  |
|[ex05](https://github.com/achrafelkhnissi/CS/blob/master/1337/DAYS/DAY13/ex05)   |[btree search item](https://github.com/achrafelkhnissi/CS/blob/master/1337/DAYS/DAY13/ex05/README.md)       |[btree_search_item.c](https://github.com/achrafelkhnissi/CS/blob/master/1337/DAYS/DAY13/ex05/btree_search_item.c)       |
|[ex06](https://github.com/achrafelkhnissi/CS/blob/master/1337/DAYS/DAY13/ex06)   |[btree level count](https://github.com/achrafelkhnissi/CS/blob/master/1337/DAYS/DAY13/ex06/README.md)           |[btree_level_count.c](https://github.com/achrafelkhnissi/CS/blob/master/1337/DAYS/DAY13/ex06/btree_level_count.c) |
|[ex07](https://github.com/achrafelkhnissi/CS/blob/master/1337/DAYS/DAY13/ex07)   |[btree apply by level](https://github.com/achrafelkhnissi/CS/blob/master/1337/DAYS/DAY13/ex07/README.md)        |[btree_apply_by_level.c](https://github.com/achrafelkhnissi/CS/blob/master/1337/DAYS/DAY13/ex07/btree_apply_by_level.c)       |
|[ex08](https://github.com/achrafelkhnissi/CS/blob/master/1337/DAYS/DAY13/ex08)   |[rb insert](https://github.com/achrafelkhnissi/CS/blob/master/1337/DAYS/DAY13/ex08/README.md)     |[rb_insert.c](https://github.com/achrafelkhnissi/CS/blob/master/1337/DAYS/DAY13/ex08/rb_insert.c)|
|[ex09](https://github.com/achrafelkhnissi/CS/blob/master/1337/DAYS/DAY13/ex09)   |[rb remove](https://github.com/achrafelkhnissi/CS/blob/master/1337/DAYS/DAY13/ex09/README.md) |[rb_remove.c](https://github.com/achrafelkhnissi/CS/blob/master/1337/DAYS/DAY13/ex09/rb_remove.c) |

## Notes
1. Tree can be called a recursive data structure.
	- (recursion is basically is reducing something in a self similar manner).
2. In a tree with `N` nodes, there will be exactly `N - 1` links.
	- `N nodes == N - 1 lineks`
3. Depth and Height:
	- Depth of `x` = Length of path from root to `x` (root index is 0)
	- Height of `x` = Number of edges in the longest path from `x` to a leaf (x index is 0 & height of leaf node is 0)
	- Height of `tree` = Height of root node (which is the number of links from the root node to the furthest leaf) 
	- To search! "Different between the height and depth of a tree"
	- Maximum depth of a tree is equal to the height of the tree
4. Binary tree: a tree in which each node can have at most 2 children.
5. Application:
	- Hierarchical data -> e.g.: file system, family.. etc.
	- Organize data -> e.g.: quick search, insertion, deletion.
	- Trie -> dictionary.
	- Network routing algorithm.
	- More..
6. Binary tree types:
	- Strict/proper -> each node can have either 2 or 0 children.
	- Complete -> All levels except possibly the last are completely filled and all nodes are as left as possible. (max n° of nodes at level `i` = `2^i`).
	- Perfect -> All levels are completely filled. (have maximum number of nodes possible for a height)
	- Balanced -> Difference between height of left and right subtree for every node id not more than 1
7. Maximum number of nodes with height `h`:
	- = 2^0 + 2^1 + 2^2 + 2^3 + 2^4 ... 2^h
	- = 2^h+1 - 1
	- n = 2^h+1 - 1 (n = number of nodes)
	```c
		while (h >= 0)
		n += pow(2, h--);
	```
8. Cost of a lost of operations on tree in terms of time, depends upon the height of the tree. (searching, inserting or removing in element)
9. Height of a tree with one node (root = leaf) is 0, Height of an empty tree is -1.
10. The difference between heights of left and right sub-trees of a node can be calculated as:
	- `diff = | hleft - hright |`
11. To google: can we replace value binary tree using arrays?
	- (like storing the addresses in an array then replace the values..)
12. To google: red black trees. 


## Resources
- [Intro to binary tree - data structures](https://www.youtube.com/watch?v=qH6yxkw0u78&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=26)
- [Tree traversal - Wikipedia](https://en.wikipedia.org/wiki/Tree_traversal#Pre-order,_NLR)
- [Tree traversal](https://www.cs.sfu.ca/~ggbaker/zju/math/traversal.html)
- [4 Types of Tree Traversal Algorithms](https://towardsdatascience.com/4-types-of-tree-traversal-algorithms-d56328450846)

## Q
1. What's the different between declaring a struct and declaring a pointer to a struct.
