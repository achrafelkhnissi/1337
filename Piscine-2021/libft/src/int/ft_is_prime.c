int	ft_is_prime(int nb)
{
	int p;

	p = 1;
	if (nb < 2)
		return (0);
	while(++p != nb)
		if (nb % p == 0)
			return (0);
	return (1);
}
