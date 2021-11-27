int	ft_recursive_factorial(int nb)
{
	int	facto;

	facto = 1;
	if (nb < 0)
		return (0);
	if (nb)
		facto = nb * ft_recursive_factorial(nb - 1);
	return (facto);
}

