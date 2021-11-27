#include <stdio.h>

void	inter(char *av1, char *av2);

int	main(int ac, char **av)
{
	int	len;

	len = 0;
	if (ac == 3)
		inter(av[1], av[2]);
	putchar('\n');
	return (0);
}

int	exist(char c, char *str, int j)
{
	int	i;
	
	i = 0;
	while (i < j)
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

void	inter(char *av1, char *av2)
{
	int	i;
	int	j;

	i = 0;
	while (av1[i])
	{
		j = 0;
		if (!exist(av1[i], av1, i))
		{
			while (av2[j])
			{
				if (av1[i] == av2[j])
				{
					putchar(av1[i]);
					break;			
				}
				j++;
			}
		}
		i++;
	}
}
