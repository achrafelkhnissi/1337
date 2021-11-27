#include <unistd.h>

void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_ft(int *nbr);
int	main(void)
{
	int	n;
	int	*p;

	n = 1337;
	p = &n;

	ft_ft(p);
	ft_putchar('\n');

	return (0);
}

void	ft_ft(int *nbr)
{
	ft_putnbr(*nbr);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	
	if (n > 9)
	{
		ft_putnbr(n / 10);
	}

	ft_putchar((n % 10) + '0');
}
