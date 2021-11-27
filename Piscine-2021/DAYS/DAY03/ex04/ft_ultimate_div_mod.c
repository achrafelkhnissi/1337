#include <unistd.h>

void	ft_putnbr(int n);
void	ft_putchar(char c);
void	ft_ultimate_div_mod(int *a, int *b);
int	main(void)
{
	int	i, j;

	i = 1337;
	j = 10;

	ft_putnbr(i);
	ft_putchar(',');
	ft_putchar(' ');
	ft_putnbr(j);
	ft_putchar('\n');

	ft_ultimate_div_mod(&i, &j);

	ft_putnbr(i);
	ft_putchar(',');
	ft_putchar(' ');
	ft_putnbr(j);
	ft_putchar('\n');

	return (0);
}

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	tmp;
	tmp = *a;

	*a = *a / *b;
	*b = tmp % *b;
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
