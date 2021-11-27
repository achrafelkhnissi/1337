int	is_power_of_2(unsigned int n)
{
	unsigned int	i;

	i = 1;
	while (i < n)
		i *= 2;
	if (i == n)
		return (1);
	return (0);
}
