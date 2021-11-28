#include "do_op.h"

int	main(int ac, char **av)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	i = 0;
	if (ac == 4)
	{
		x = atoi(av[1]);
		y = atoi(av[3]);
		while (i < 5)
		{
			if (av[2][0] == *g_op[i].op)
				printf("%d", g_op[i].func(x, y));
			i++;
		}
	}
	printf("\n");
	return (0);
}
