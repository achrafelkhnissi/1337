#ifndef FT_BTREE_H
#define FT_BTREE_H

#include <stdlib.h>

enum e_rb_color
{
	RB_BLACK,
	RB_RED
};

typedef struct		s_rb_node	
{
	struct s_rb_node *parent;
	struct s_rb_node *left;
	struct s_rb_node *right;
	void	*data;
	enum e_rb_color	color;
}	t_btree;

t_btree	*btree_create_node(void *item);

#endif

