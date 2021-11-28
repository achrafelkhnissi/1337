#include <stdio.h>
#include <unistd.h>

void	search_and_replace(char *str, char c1, char s2);

int	main(int ac, char **av)
{
	if (ac == 4 && !(av[2][1] || av[3][1]))
		search_and_replace(av[1], *av[2], *av[3]);
	write(1, "\n", 1);
	return (0);
}

void	search_and_replace(char *str, char c1, char c2)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c1)
			write(1, &c2, 1);
		else
			write(1, &str[i], 1);
		i++;
	}
}
