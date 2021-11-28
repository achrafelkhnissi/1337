int	ft_count_if(char **tab, int(*f)(char*))
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (tab[i][0])
	{
		if (f(tab[i]))
			count++;
		i++;
	}
	return (count);
}
