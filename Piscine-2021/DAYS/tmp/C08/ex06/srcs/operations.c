#include <stdio.h>

int	ft_sub(int x, int y)
{
	return x - y;
}

int	ft_add(int x, int y)
{
	return x + y;
}

int	ft_mul(int x, int y)
{
	return x * y;
}

int	ft_div(int x, int y)
{
	if (x == 0 || y == 0)
	{
		printf("Stop: division by zero\n");
		return (-1);
	}
	return x / y;
}

int	ft_mod(int x, int y)
{
	if (x == 0 || y == 0)
	{
		printf("Stop: modulo by zero\n");
		return (-1);
	}
	return x % y;
}


/*
   "-" = sub,
   "+" = add,
   "*" = mul,
   "/" = div,
   "%" = mod,
*/

