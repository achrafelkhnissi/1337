#include "../includes/adv_opp.h"
#include "../includes/ft_opp.h"

int	main(int ac, char **av)
{
	int	result;
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	i = 0;
	result = 0;
	if (ac == 4)
	{
		x = atoi(av[1]);
		y = atoi(av[3]);
		
		printf("x = %d, y = %d\n", x, y);
		while (i < 5)
		{
			if (*g_opptab[i].op == av[2][0] && !av[2][1])
			{
				result = g_opptab[i].fun(x, y);
				printf("result = %d\n", result);
				return (0);
			}
			i++;
		}
		g_opptab[i].fun(x, y);
	}
	return (0);
}
