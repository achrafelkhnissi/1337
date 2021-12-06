/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:19:19 by ael-khni          #+#    #+#             */
/*   Updated: 2021/12/06 22:21:13 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_btree
{
	int	data;
	struct	s_btree *left;
	struct	s_btree *right;
}	t_btree;

/*
int	queue[50];
int	front;
int	rear;
*/

t_btree	*create_node(int	data);
void	insert_node(t_btree **root, int data);
void	print_btree(int data, int lv, int is_first_elm);
int	max(int x, int y);
int	level_count(t_btree *root);
void	apply_by_level(t_btree *root, void (*applyf)(int data, int curr_lv, int is_first_elm));
void	apply_to_level(t_btree *root, int curr_lv, int *levels, 
		void (*applyf)(int data, int curr_lev, int is_first_elem));

int	main(void)
{
	t_btree	*root;
	int	level;

	level = 0;
	root = NULL;
	insert_node(&root, 10);
	insert_node(&root, 5);
	insert_node(&root, 20);
	insert_node(&root, 2);
	insert_node(&root, 7);
	insert_node(&root, 6);
	insert_node(&root, 15);
	insert_node(&root, 25);
	apply_by_level(root, print_btree);
	level = level_count(root);
	printf("\nLevels = %d\n", level);
	free(root);
	return (0);
}

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

void	insert_node(t_btree **root, int data)
{
	if (!*root)
	{
		*root = create_node(data);
		return ;
	}
	if (data <= (*root)->data)
		insert_node(&(*root)->left, data);
	else
		insert_node(&(*root)->right, data);
}

void	print_btree(int data, int lv, int is_first_elm)
{
	printf("%d\t| L%d - F%d\n", data, lv, is_first_elm);
}
int	max(int x, int y)
{
	if (x > y)
		return (x);
	return (y);
}
int	level_count(t_btree *root)
{
	if (!root)// || (!root->left && !root->right))
		return (-1);
	return (max(level_count(root->left), level_count(root->right)) + 1);
}

int	g_level;

void	apply_by_level(t_btree *root, void (*applyf)(int data, int curr_lv, int is_first_elm))
{
	int	count;
	int	*levels;
	int	i;

	g_level = 0;
	if (!root)
		return ;
	count = level_count(root);
	if (!(levels = (int*)malloc(sizeof(int) * count)))
		return ;
	while (g_level <= count)
	{
		i = 0;
		while (i < count)
			levels[i++] = 0;
		apply_to_level(root, 0, levels, applyf);
		g_level++;
	}
}

void	apply_to_level(t_btree *root, int curr_lv, int *levels, 
		void (*applyf)(int data, int curr_lev, int is_first_elem))
{
	int	is_first_elem;

	is_first_elem = 1;
	if (levels[curr_lv] == 1)
		is_first_elem = 0;
	else
		levels[curr_lv] = 1;
	if (curr_lv == g_level)
		applyf(root->data, curr_lv, is_first_elem);
	if (root->left)
		apply_to_level(root->left, curr_lv + 1, levels, applyf);
	if (root->right)
		apply_to_level(root->right, curr_lv + 1, levels, applyf);
}
