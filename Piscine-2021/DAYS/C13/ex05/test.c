/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:19:01 by ael-khni          #+#    #+#             */
/*   Updated: 2021/12/06 22:20:14 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "btree_search_item.c"


t_btree	*btree_create_node(void *item)
{
	t_btree	*new;

	new = malloc(sizeof(t_btree));
	if (!new)
		return (NULL);
	new->item = item;
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
	printf("value =	%s\n", root->item);
	printf("left ");

	print_tree(root->left);
	printf("right ");

	print_tree(root->right);
	printf("done.\n");
}

/* The **pointer is there because if the tree root is null
 * i need to be able change the address that the root pointer
 * points to. It is not possible with a single pointer */
void	insert_node(t_btree **root, void *value, int (*cmp)(const char *, const char *))
{
	t_btree	*curr = *root;

	if (!curr) /* Tree is empty */
	{
		*root = btree_create_node(value);
		return ;
	}
	if (cmp(value, curr->item) < 0)
		return insert_node(&(curr->left), value, cmp);
	else
		return insert_node(&(curr->right), value, cmp);
}

int	main(void)
{
	t_btree	*root;
	char	*r;
	char	*n;

	root = 0;
	n = "7";
	insert_node(&root, "5", strcmp);
	insert_node(&root, "4", strcmp);
	insert_node(&root, "7", strcmp);
	insert_node(&root, "1", strcmp);
	insert_node(&root, "9", strcmp);
	insert_node(&root, "4", strcmp);
	print_tree(root);

	r = btree_search_item(root, n, strcmp);
	if (!r)
		printf("\nItem not found!\n");
	else
		printf("\nItem found: %s\n", r);
	free(root);
	return(0);
}
