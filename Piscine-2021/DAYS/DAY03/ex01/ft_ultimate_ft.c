#include <unistd.h>

void	ft_putnbr(int n);
void	ft_putchar(char c);
void	ft_ultimate_ft(int *********nbr);
int	main(void)
{
	int	number;
	int	*p;
	int	**p2;
	int	***p3;
	int	****p4;
	int	*****p5;
	int	******p6;
	int	*******p7;
	int	********p8;
	int	*********p9;

	p = &number;
	p2 = &p;
	p3 = &p2;
	p4 = &p3;
	p5 = &p4;
	p6 = &p5;
	p7 = &p6;
	p8 = &p7;
	p9 = &p8;

	number = 1337;

	ft_ultimate_ft(p9);
	ft_putchar('\n');

	return (0);
}

void	ft_ultimate_ft(int *********nbr)
{
	ft_putnbr(*********nbr);
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
