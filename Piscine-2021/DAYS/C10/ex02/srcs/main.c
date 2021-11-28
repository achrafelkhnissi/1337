#include "../includes/ft_tail.h"

int	main(int ac, char **av)
{
	int	i;
	int	return_value;
	int	bytes;

	i = 1;
	bytes = 0;
	return_value = 0;
	if (ac == 1)
		stdin_to_stdout();
	else
	{
		bytes = check_flag(av);
		if (bytes)
			i = 3;
		else if (bytes == -1)
			return (bytes);
		while (i < ac)
			ft_tail(ac, bytes, av[i++]);
	}
	return (return_value);
}

