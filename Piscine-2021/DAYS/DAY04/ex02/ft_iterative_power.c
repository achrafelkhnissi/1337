#include <stdio.h>

#define N -8
#define P 2

int	ft_iterative_power(int nb, int power)
{
	int	p;

	p = 1;
	if (power < 0)
		return (0);
	while (power--)
		p *= nb;
	return (p);
}

int	main(int argc, char **argv)
{
	printf("%d^%d = %d\n", N, P, ft_iterative_power(N, P));

	if (argc == 3)
		printf("%c^%c = %d\n", argv[1][0], argv[2][0], ft_iterative_power(argv[1][0] - '0', argv[2][0] - '0'));
	return (0);
}
