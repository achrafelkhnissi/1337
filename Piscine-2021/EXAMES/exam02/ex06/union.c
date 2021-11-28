#include <stdio.h>

void	ft_union(char *av1, char *av2);
int	exist(char c, char *str, int index);

int	main(int ac, char **av)
{
	int	len;

	len = 0;
	if (ac == 3)
		ft_union(av[1], av[2]);
	putchar('\n');
	return (0);
}

void	ft_union(char *av1, char *av2)
{
	int	i;
	int	len;

	i = 0;
	while (av1[i])
	{
		if (!exist(av1[i], av1, i))
			putchar(av1[i]);
		i++;
	}
	len = i;
	i = 0;
	while (av2[i])
	{
		if (!exist(av2[i], av2, i))
			if (!exist(av2[i], av1, len))
				putchar(av2[i]);
		i++;
	}
}

int	exist(char c, char *str, int index)
{
	int	i;
	
	i = 0;
	while (i < index)
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}
