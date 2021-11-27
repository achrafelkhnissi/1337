#include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	int	facto;

	facto = 1;
	if (nb < 0)
		return (0);
	if (nb)
		facto = nb * ft_recursive_factorial(nb - 1);
	return (facto);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		printf("%s! = %d\n", argv[1], ft_recursive_factorial(argv[1][0] - '0'));
	return (0);
}
