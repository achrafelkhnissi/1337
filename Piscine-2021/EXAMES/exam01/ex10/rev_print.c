#include <unistd.h>

void	rev_print(char *str);

int	main(int ac, char **av)
{
	if (ac == 2)
		rev_print(av[1]);
	write(1, "\n", 1);
	return (0);
}

void	rev_print(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i)
		write(1, &str[--i], 1);
}
