#include "ft_btree.h"

int	g_level;

int	max(int x, int y)
{
	if (x > y)
		return (x);
	return (y);
}

int	btree_level_count(t_btree *root)
{
	if (!root) // || (!root->left && !root->right)) return (0);
		return (-1);
	return (max(btree_level_count(root->left), btree_level_count(root->right)) + 1);
}

void	apply_to_level(t_btree *root, int curr_lv, int *levels,
		void (*applyf)(void *item, int curr_lev, int is_first_elem))
{
	int	is_first_elem;

	is_first_elem = 1;
	if (levels[curr_lv] == 1)
		is_first_elem = 0;
	else
		levels[curr_lv] = 1;
	if (curr_lv == g_level)
		applyf(root->item, curr_lv, is_first_elem);
	if (root->left)
		apply_to_level(root->left, curr_lv + 1, levels, applyf);
	if (root->right)
		apply_to_level(root->right, curr_lv + 1, levels, applyf);
}

void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item, int current_level, int is_first_elem))
{
	int	count;
	int	*levels;
	int	i;

	g_level = 0;
	if (!root)
		return ;
	count = btree_level_count(root);
	if (!(levels = (int*)malloc(sizeof(int) * count)))
		return ;
	i = 0;
	while (i < count)
		levels[i++] = 0;
	while (g_level <= count)
	{
		apply_to_level(root, 0, levels, applyf);
		g_level++;
	}
}
