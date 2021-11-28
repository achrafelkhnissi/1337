#include "ft_stock_par.h"

int	main(int ac, char **av)
{
	t_stock_par	*t_stock;
	int	i;

	i = 0;
	if (ac)
	{
		t_stock = ft_param_to_tab(ac, av);
		ft_show_tab(t_stock), i++;
	}
	return (0);
}
