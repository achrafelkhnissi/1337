#include <stdio.h>

int	ft_sqrt(int nb);
int	main(void)
{
	int	i;

	i = 0;
	while (i++ < 100)
		if (ft_sqrt(i) > 0)
			printf("√%d\t= %d\n", i, ft_sqrt(i));
	return (0);
}

int	ft_sqrt(int nb)
{
	int	number;

	number = 1;
	while (number < nb)
	{
		if ((number * number) == nb)
			return (number);
		number++;
	}
	return (0);
}
