int	ft_any(char **tab, int(*f)(char *))
{
	int	i;

	i = 0;
	/* tab[i][0] != 0 */
	while (tab[i][0])
	{
		/* f(tab[i]) > 0 */
		if (f(tab[i]))
			return (1);
		i++;
	}
	return (0);
}
