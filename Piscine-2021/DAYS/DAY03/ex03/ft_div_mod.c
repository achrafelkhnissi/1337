#include <unistd.h>

void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_div_mod(int a, int b, int *div, int *mod);
int	main(void)
{
	int	i, j, d, m;

	i = 1337;
	j = 10;

	ft_div_mod(i, j, &d, &m);

	ft_putnbr(d);
	ft_putchar('\n');
	ft_putnbr(m);
	ft_putchar('\n');

	return (0);
}

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
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

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
