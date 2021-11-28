void ft_advanced_sort_wordtab(char **tab, int(*cmp)(char *, char *))
{
	char	*tmp;
	int	i;

	i = 0;
	while (tab[i + 1])
	{
		if (cmp(tab[i], tab[i + 1]) > 0)
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
		}
		i++;
	}
}
