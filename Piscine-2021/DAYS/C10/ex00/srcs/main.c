#include "../includes/display_file.h"

int	main(int ac, char **av)
{
	if (ac == 1)
		ft_puterr("File name missing.\n");
	else if (ac == 2)
		display_file(av[1]);
	else
		ft_puterr("Too many arguments.\n");
	return (0);
}
