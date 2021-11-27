#include "../includes/ft_cat.h"

int	main(int ac, char **av)
{
	int	i;
	int	return_value;

	i = 1;
	return_value = 0;
	if (ac == 1)
		stdin_to_stdout();
	else
	{
		while (i < ac)
			if(ft_cat(av[i++]) == 1)
				return_value = 1;
	}
	return (return_value);
}

