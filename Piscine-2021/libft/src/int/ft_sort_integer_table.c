#include "../../includes/libft.h"

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;

	i = size;
	while (--i)
	{
		if (tab[i] < tab[i - 1])
		{
			ft_swap(&tab[i], &tab[i - 1]);
			i = size;
		}
	}
}

