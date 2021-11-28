#include "ft_stock_par.h"
#include <stdlib.h>
#include <string.h>

struct s_stock_par	*ft_param_to_tab(int ac, char **av)
{
	t_stock_par *stock;
	int			i;
	int			j;

	i = 0;
	stock = malloc(sizeof(t_stock_par) * (ac + 1));
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
			j++;
		stock[i].size_param = j;
		stock[i].str = av[i];
		stock[i].copy = strdup(av[i]);
		stock[i].tab = ft_split_whitespaces(av[i]);
		i++;
	}
	stock[i].str = 0;
	return (stock);
}
/*
 * 1. create an array of structures size of ac
 * 2. assign param[i] to struct[i]
 * 	- size_param = strlen(param)
 * 	- str = param;
 * 	- copy = strdup(param)
 * 	- tab = split_whitespaces(param)
 * 3. return the struct.
 */
