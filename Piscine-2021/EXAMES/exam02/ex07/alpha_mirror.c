#include <stdio.h>

int	main(int ac, char **av)
{
	int 	i;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i])
		{
			if (av[1][i] >= 'A' && av[1][i] <= 'Z')
				putchar('M' - (av[1][i] - 'N'));
			else if (av[1][i] >= 'a' && av[1][i] <= 'z')
				putchar('m' - (av[1][i] - 'n'));
			else
				putchar(av[1][i]);
			i++;
		}
	}
	putchar('\n');
	return (0);
}
