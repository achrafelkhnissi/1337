#include <unistd.h>

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		int exist[255] = {0};
		char	*s1 = av[1];
		char	*s2 = av[2];
		while (*s2)
			exist[(int)*s2++] = 1;
		while (*s1)
		{
			if (exist[(int)*s1])
			{
				write(1, s1, 1);
				exist[(int)*s1] = 0;
			}
			s1++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
