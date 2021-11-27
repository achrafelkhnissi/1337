## Exercise 07: btree_apply_by_level

- Create a function `btree_apply_by_level` which applies the function passed as argument to each node of the tree. The tree must be browsed level by level. The function called will take three arguments:
	- The first argument, the type `void *`, will correspond to the node's item;
	- The second argument, of type `int`, corresponds to the level on which we find: 0 for root, 1 for children, 2 for grand-children, etc.;
	- The third argument, of type `int`, is worth 1 if it's the first `node` of the level, or 0 otherwise.
- Here's how it should be prototyped:
```c
void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item, int current_level, int is_first_elem));
```


## Notes

#### Using queue:
1. create an array that represents a queue
2. create 2 int variables that represents the front and the rear elements of the queue.
3. save the root node in the queue and the left node second then the right node third.
	- if the left node is not null add it to the queue and increment the rear variable by
	- same of the right node
4. apply the applyf function of the first element of the queue then increment the front variable. (first in first out)
5. then going to the left child of the root and repeat the process above!.
	- save left and right nodes & increase the rear variable.
	- read the current node and then increase the front variable.

#### !
1. Add all nodes in a level order fashion to a queue
2. Then go through the binary tree in pre-order traversal
	- compare the node in the queue with the one in the binary tree
	- if it's the same then apply the function to it + current level && if its first elem
3. Repeat 2 until the queue is empty.

#### Funcitons
- Apply_by_level()
- Level_count()
- Max() - can add it to level_count()!
- Apply_to_level()
- first_elem_check()
 

#### Level-Order Traversal Algorithm
1. Create an empty queue q
2. tmp_node = root
3. loop while tmp_node is not NULL
	1. print tmp_node->data.
	2. Enqueue tmp_node's children (first left then right children) to q
	3. Dequeue a node from q and assign it's value to tmp_node.
