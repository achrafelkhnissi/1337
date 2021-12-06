#include "../includes/do-op.h"

int	do_op(int (*f)(int, int), int x, int y)
{
	int	result;

	result = f(x, y);	
	return (result);
}

/*
   "-" = sub,
   "+" = add,
   "*" = mul,
   "/" = div,
   "%" = mod,
*/
