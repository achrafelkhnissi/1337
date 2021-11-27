#include <stdio.h>

int	ft_fibonacci(int index);

int	main(int argc, char **argv)
{
	char	n;

	n = argv[1][0] - '0';
	if (argc == 2)
		printf("fib(%d) = %d\n", n, ft_fibonacci(n));
	return (0);
}

int	ft_fibonacci(int index)
{
	int	result;

	if (index < 0)
		return (-1);
	if (index <= 1)
		return (index); 	
	result = ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
	return (result);
}
