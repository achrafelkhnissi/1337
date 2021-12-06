#ifndef ADV_DO_OP_H
#define ADV_DO_OP_H

#include <stdlib.h>
#include <stdio.h>

typedef int (*t_oppf) (int, int);

typedef struct s_opp
{
	char	*op;
	t_oppf	fun;
}		t_opp;

int	ft_sub(int x, int y);
int	ft_add(int x, int y);
int	ft_mul(int x, int y);
int	ft_div(int x, int y);
int	ft_mod(int x, int y);
int	ft_usage(int x, int y);

#endif
