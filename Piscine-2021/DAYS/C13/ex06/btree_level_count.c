/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:19:03 by ael-khni          #+#    #+#             */
/*   Updated: 2021/12/06 22:20:16 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdio.h>
#include <string.h>

void	btree_insert_data(t_btree **root, int item, int (*cmpf)(const char*, const char*));
void	print_tree(t_btree *root);
int	btree_level_count(t_btree *root);

int	main(void)
{
	t_btree	*root;

	root = NULL;
	btree_insert_data(&root, 10, strcmp);
	btree_insert_data(&root, 9, strcmp);
	btree_insert_data(&root, 7, strcmp);
	btree_insert_data(&root, 8, strcmp);
	btree_insert_data(&root, 6, strcmp);
	btree_insert_data(&root, 4, strcmp);
	btree_insert_data(&root, 11, strcmp);
	btree_insert_data(&root, 15, strcmp);
	btree_insert_data(&root, 20, strcmp);

	print_tree(root);
	printf("level count = %d\n", btree_level_count(root));
	free(root);
	return (0);
}

int	max(int x, int y)
{
	if (x > y)
		return (x);
	return (y);
}

int	btree_level_count(t_btree *root)
{
	if (!root || (!root->left && !root->right))
		return (0);
	return (max(btree_level_count(root->left), btree_level_count(root->right)) + 1);
}

t_btree *btree_create_node(int item)
{
	t_btree	*new;

	new = malloc(sizeof(t_btree));
	if (!new)
		return (NULL);
	new->item = item;
	new->right = NULL;
	new->left = NULL;
	return (new);
}

void	btree_insert_data(t_btree **root, int item)
{
	if (!*root)
	{
		*root = btree_create_node(item);
		return ;
	}
	if (item <= (*root)->item)
		return (btree_insert_data(&(*root)->left, item));
	else
		return (btree_insert_data(&(*root)->right, item));
}


void	print_tree(t_btree *root)
{
	if (root)
	{
		printf("%s\n", root->item);
		print_tree(root->left);
		print_tree(root->right);
	}
}

