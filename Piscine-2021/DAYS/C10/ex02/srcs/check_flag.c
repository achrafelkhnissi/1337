#include "../includes/ft_tail.h"

int	check_flag(char **av)
{
	int	bytes;
	int	i;

	bytes = 0;
	i = 2;
	if (av[1][0] == '-')
	{
		if (av[1][1] == 'c' && !av[1][2])
		{
			if (!av[2])
			{
				write(2, "ft_tail: option requires an argument -- c\n", 42);
				write(2, "usage: ft_tail [ -c # ] [file ...]\n", 35);
				return (-1);
			}
			else
			{
				bytes = ft_atoi(av[2]);
				return (bytes);
			}
		}
		else if (av[1][1] == 'c' && av[1][2])
		{
			write(2, "ft_tail: illegal offset -- ", 28);
			while (i < ft_strlen(av[1]))
				write(2, &av[1][i++], 1);
			write(2, "\n", 1);
		}
		else
		{
			write(2, "ft_tail: illegal option -- ", 28);
			write(2, &av[1][1], 1);
			write(2, "\n", 1);
			write(2, "usage: ft_tail [ -c # ] [file ...]\n", 35);
		}
	}
	return (0);
}
