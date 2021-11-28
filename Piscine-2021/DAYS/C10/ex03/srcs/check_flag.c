#include "../includes/ft_hexdump.h"

int	check_flag(char **av)
{
	if (av[1][0] == '-')
	{
		if (av[1][1] == 'C')
		{
			if (av[1][2])
			{
				write(2, "ft_hexdump: illegal option -- ", 31);
				write(2, &av[1][2], 1);
				write(2, "\n", 1);
				write(2, "usage: ft_hexdump [ -C ] file ...\n", 35);
				return (-1);
			}
			else if (!av[2])
			{
				write(2, "usage: ft_hexdump [ -C ] file ...\n", 35);
				return (-1);
			}
			return (1);
		}
		else
		{
			write(2, "ft_hexdump: illegal option -- ", 30);
			write(2, &av[1][1], 1);
			write(2, "\n", 1);
			write(2, "usage: ft_hexdump [ -C ] file ...\n", 35);
			return (-1);
		}
	}
	return (0);
}
