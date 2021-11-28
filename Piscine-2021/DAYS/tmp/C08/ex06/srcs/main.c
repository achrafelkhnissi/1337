#include "../includes/do-op.h"

int	main(int ac, char **av)
{
	int	x;
	int	y;
	int	result;

	x = 0;
	y = 0;
	result = 0;
	if (ac == 4)
	{
		x = atoi(av[1]);
		y = atoi(av[3]);
	
		printf("x = %d, y = %d\n", x, y);
		if (*av[2] == '+')
			result = do_op(ft_add, x, y);
		if (*av[2] == '-')
			result = do_op(ft_sub, x, y);
		if (*av[2] == '*')
			result = do_op(ft_mul, x, y);
		if (*av[2] == '/')
			result = do_op(ft_div, x, y);
		if (*av[2] == '%')
			result = do_op(ft_mod, x, y);
		printf("result = %d\n", result);
	}
	return (0);
}

/*
   "-" = sub,
   "+" = add,
   "*" = mul,
   "/" = div,
   "%" = mod,
*/
