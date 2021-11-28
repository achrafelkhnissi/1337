#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
		int (*cmpf)(const char *, const char *))
{
	void	*res;

	res = NULL;
	if (!root)
		return (NULL);
	res = btree_search_item(root->left, data_ref, cmpf);
	if (cmpf(data_ref, root->item) == 0 && !res)
		return (root->item);
	if (!res)
		res = btree_search_item(root->right, data_ref, cmpf);
	return (res);
}
