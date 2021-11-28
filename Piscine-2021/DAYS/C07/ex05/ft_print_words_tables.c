#include "split.c"

void	ft_print_words_tables(char **tab);

int	main(void)
{
	char	**str;
	char	*test = "Future is loading!";

	str = ft_split_whitespaces(test);
	ft_print_words_tables(str);
	return (0);
}

void	ft_print_words_tables(char **tab)
{
	int i;
	int j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			putchar(tab[i][j]);
			j++;
		}
		putchar('\n');
		i++;
	}
}
