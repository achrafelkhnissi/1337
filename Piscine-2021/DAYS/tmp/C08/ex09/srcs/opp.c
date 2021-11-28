#include <stdio.h>
#include <unistd.h>

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
	/* Does not work! Unless you escape the * sign in the command line "\*" */
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

int	ft_usage(int a, int b)
{
	write(1, "error : only [ - + * / % ] are accepted.\n", 50);
	return (a + b);
}
