#ifndef DO_OP_H
#define DO_OP_H

#include <stdio.h>
#include <stdlib.h>

typedef int (*t_func) (int, int);

typedef struct s_op
{
	char	*op;
	t_func	func;
}	t_op;

int	ft_add(int x, int y);
int	ft_sub(int x, int y);
int	ft_mul(int x, int y);
int	ft_div(int x, int y);
int	ft_mod(int x, int y);

t_op	g_op[5] = 
{
	{"+", &ft_add},
	{"-", &ft_sub},
	{"*", &ft_mul},
	{"/", &ft_div},
	{"%", &ft_mod}
};

#endif
