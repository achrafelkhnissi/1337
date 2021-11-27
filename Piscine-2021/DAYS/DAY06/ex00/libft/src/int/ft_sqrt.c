int	ft_sqrt(int nb)
{
	int	number;

	number = 1;
	while (number < nb)
	{
		if ((number * number) == nb)
			return (number);
		number++;
	}
	return (0);
}
