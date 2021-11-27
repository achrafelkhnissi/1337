#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		while (*argv[0])
			ft_putchar(*argv[0]++);
	ft_putchar('\n');
	return (0);
}
