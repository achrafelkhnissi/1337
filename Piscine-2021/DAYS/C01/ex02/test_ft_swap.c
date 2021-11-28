#include <unistd.h>

void	ft_swap(int *a, int *b);
void	ft_putchar(char c);
void	ft_putnbr(int nbr);
int	main(void)
{
	int	i, j;
	i = 42;
	j = 1337;

	ft_putnbr(i);
	ft_putchar(',');
	ft_putchar(' ');
	ft_putnbr(j);
	ft_putchar('\n');

	ft_swap(&i, &j);

	ft_putnbr(i);
	ft_putchar(',');
	ft_putchar(' ');
	ft_putnbr(j);
	ft_putchar('\n');

	return (0);
}

void ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_putnbr(int nbr)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}

	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
	}

	ft_putchar((nbr % 10) + '0');
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
