#include <stdio.h>

#define N 8
#define P 3

int	ft_recursive_power(int nb, int power)
{
	int	p;

	p = 1;
	if (power < 0)
		return (0);
	if (power)
		p = nb * ft_recursive_power(nb, power - 1);
	return (p);
}

int	main(void)
{
	printf("number = %d\npower = %d\nresult = %d\n",
		N, P, ft_recursive_power(N, P));
	return 0;
}
