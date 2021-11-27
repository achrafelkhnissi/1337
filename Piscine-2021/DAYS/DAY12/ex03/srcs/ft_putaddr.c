#include "../includes/ft_hexdump.h"

void	ft_putnbr_base(int nbr, int nbase)
{
	char	*base = "0123456789abcdef";

	if (nbr >= nbase)
		ft_putnbr_base(nbr / nbase, nbase);
	ft_putchar(base[nbr % nbase]);
}

void	ft_putaddr(int nbr, int flag)
{
	int	i;
	int	len;

	len = 2;
	if (flag)
		len = flag;
	i = nbr;
	while (i /= 16)
		len++;
	while (i++ < 8 - len)
		ft_putchar('0');
	ft_putnbr_base(nbr, 16);
	if (flag == 1)
		ft_putchar(' ');
	ft_putchar(' ');
}
