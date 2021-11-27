#include <unistd.h>

void	ulstr(char *str);
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		ulstr(av[1]);
	write(1, "\n", 1);
	return (0);
}

void	ulstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			ft_putchar(str[i] - 32);
		else if (str[i] >= 'A' && str[i] <= 'Z')
			ft_putchar(str[i] + 32);
		else
			ft_putchar(str[i]);
		i++;
	}
}
