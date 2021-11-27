#include <unistd.h>

void	alpha_mirror(char *str);
void	ft_putchar(char c);

int	main(int ac, char **av)
{
	if (ac == 2)
		alpha_mirror(av[1]);
	write(1, "\n", 1);
	return (0);
}

void	alpha_mirror(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			ft_putchar('a' - str[i] + 'z');
		else if (str[i] >= 'A' && str[i] <= 'Z')
			ft_putchar('A' - str[i] + 'Z');
		else
			ft_putchar(str[i]);
		i++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

