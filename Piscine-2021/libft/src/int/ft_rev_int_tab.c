#include "../../includes/libft.h"

void	ft_rev_int_tab(int *tab, int size)
{
	int	start;
	int	end;
	int	middle;

	start = 0;
	end = size - 1;
	middle = end / 2;

	while (start <= middle)
	{
		ft_swap(&tab[start++], &tab[end--]);
	}
}
