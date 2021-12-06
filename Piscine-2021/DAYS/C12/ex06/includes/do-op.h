#ifndef DO_OP_H
#define DO_OP_H

#include <stdlib.h>
#include <stdio.h>

int	ft_sub(int x, int y);
int	ft_add(int x, int y);
int	ft_mul(int x, int y);
int	ft_div(int x, int y);
int	ft_mod(int x, int y);

int     do_op(int (*f)(int, int), int x, int y);

#endif
