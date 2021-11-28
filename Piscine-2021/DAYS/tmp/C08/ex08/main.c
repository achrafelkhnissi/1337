#include <stdio.h>
#include "split.c"
#include "ft_strcmp.c"
#include "ft_advanced_sort_wordtab.c"

int	main(int ac, char **av)
{
	char	**tab;
	int	i;

	i = 0;
	if (ac == 2)
	{
		tab = ft_split_whitespaces(av[1]);
		ft_advanced_sort_wordtab(tab, ft_strcmp);
		while (tab[i])
		{
			printf("str[%d] = %s\n", i, tab[i]);
			i++;
		}
	}
	return (0);
}
