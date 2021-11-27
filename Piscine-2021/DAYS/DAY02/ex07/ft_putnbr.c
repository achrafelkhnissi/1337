#include <unistd.h>

void	ft_putchar(char c);
void	ft_putnbr(int nb);
int	main(void)
{
	ft_putnbr(1337);
	ft_putchar('\n');
	ft_putnbr(-1337);
	ft_putchar('\n');
	ft_putnbr(1);
	ft_putchar('\n');
	ft_putnbr(13);
	ft_putchar('\n');
	ft_putnbr(133);
	ft_putchar('\n');

	return (0);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	
	if (nb >= 10)
	{
		int	n[10];
		int	i;

		i = 0;
	
		while (nb)
		{
			n[i++] = nb % 10;
			nb = nb / 10;
		}

		while (i)
			ft_putchar(n[--i] + '0');
	}
	else
		ft_putchar(nb + '0');
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
