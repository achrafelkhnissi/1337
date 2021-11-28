/* test */

#include <stdio.h>
#include <stdlib.h>

typedef struct		s_btree
{
	int		data;
	struct s_btree	*left;
	struct s_btree	*right;
}			t_btree;

t_btree	*create_node(int data)
{
	t_btree	*new;

	new = malloc(sizeof(t_btree));
	if (!new)
		return (NULL);
	new->data = data;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

void	print_tree(t_btree *root)
{
/*
	if (root)
	{
		printf("%s\n", root->data);
		print_tree(root->left);
		print_tree(root->right);
	}
*/
	if (!root)
	{
		printf("--<empty>--\n");
		return ;
	}
	printf("value =	%d\n", root->data);
	printf("left ");

	print_tree(root->left);
	printf("right ");

	print_tree(root->right);
	printf("done.\n");
}

/* The **pointer is there because if the tree root is null
 * i need to be able change the address that the root pointer
 * points to. It is not possible with a single pointer */
int	insert_node(t_btree **root, int value)
{
	t_btree	*curr = *root;

	if (!curr) /* Tree is empty */
	{
		*root = create_node(value);
		return (1);
	}
	if (value < curr->data)
		return insert_node(&(curr->left), value);
	else
		return insert_node(&(curr->right), value);
}

int	search_tree(t_btree *root, int value)
{
	if (!root)
		return (0);
	if (root->data == value)
		return (1);
	if (value < root->data)
		return search_tree(root->left, value);
	else
		return search_tree(root->right, value);
}

int	main(void)
{
	t_btree	*root;
	char	*n;

	root = 0;
	n = "7";
	insert_node(&root, 10);
	insert_node(&root, 14);
	insert_node(&root, 7);
	insert_node(&root, 12);
	insert_node(&root, 9);
	insert_node(&root, 4);
	print_tree(root);

	//printf("%s -> %s\n", n, search_tree(root, n) ? "exist" : "doesn't exist");

	free(root);
	return(0);
}
