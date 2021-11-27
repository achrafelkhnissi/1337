int	ft_recursive_power(int nb, int power)
{
	int	p;

	p = 1;
	if (power < 0)
		return (0);
	if (power)
		p = nb * ft_recursive_power(nb, power - 1);
	return (p);
}

