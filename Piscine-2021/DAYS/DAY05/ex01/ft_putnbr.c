#include <stdio.h>

void	ft_putnbr(int nb);
int	main(void)
{
	ft_putnbr(1337);
	putchar('\n');

	return (0);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		putchar('-');
		nb = -nb;
	}
	
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
	}

	putchar((nb % 10) + '0');
}
