#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *))
{
	if (!*root)
	{
		*root = btree_create_node(item);
		return ;
	}
	if (cmpf(item, (*root)->item) < 0)
		return (btree_insert_data(&(*root)->left, item, cmpf));
	else
		return (btree_insert_data(&(*root)->right, item, cmpf));
}

