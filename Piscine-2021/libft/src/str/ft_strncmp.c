int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	
	i = 0;
	if (!n)
		return (0);
	while (s1[i] == s2[i] && s1[i] && s2[i] && i < n - 1)
		i++;

	return (s1[i] - s2[i]);
}
