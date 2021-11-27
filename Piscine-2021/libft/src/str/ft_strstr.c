char	*ft_strstr(char *str, char *to_find)
{
	int	s;
	int	f;

	s = 0;
	if (!to_find[0])
		return (str);
	while (str[s])
	{
		f = 0;
		while (str[s + f] == to_find[f] && str[s + f])
		{
			if (to_find[f + 1] == '\0')
				return (&str[s]);
			f++;
		}
		s++;
	}
	return (0);
}
