/* from  print memory*/

#include <stdio.h>
#include <stdlib.h>

void	ft_putaddr_base(int nbr, int nbase);

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		int	len;
		int	nb;
		int	i;
	
		i = 0;
		len = 1;
		nb = atoi(av[1]);
		ft_putaddr_base(nb, 16);
		putchar('\n');
		while (nb /= 10)
			len++;
		printf("len = %d\n", len);
		while (i++ < (8 - len))
			putchar('0');
		printf("%s\n", av[1]);
	}
	return (0);
}

void	ft_putaddr_base(int nbr, int nbase)
{
	static	int checked;
	char	*base = "0123456789abcdef";
	int	i;
	int	len;

	len = 1;
	i = nbr;
/*	to print the leading 0s.
	while ((i /= 16) && !checked)
		len++;
	i = 0;
	if (!checked)
	{
		checked = 1;
		while (i++ < (8 - len))
			putchar('0');
	}
*/
	if (nbr >= nbase)
		ft_putaddr_base(nbr / nbase, nbase);
	putchar(base[nbr % nbase]);
	checked = 0;
}

