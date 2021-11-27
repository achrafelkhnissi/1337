#include <stdlib.h>
#include <stdio.h>

char	*ft_itoa_base(int nbr, int nbase);
int	main(void)
{
	char	*str;
	int	nb;
	int	i;

	nb = 1337;
	i = 0;
	str = ft_itoa_base(nb, 10);
	while (str[i])
		putchar(str[i++]);
	putchar('\n');
	return (0);
}

/* Calculate the number of digits in nb */
int	nbrlen(int nb, int nbase)
{
	int	len;

	len = 0;
	if (nb < 0)
	{
		nb = -nb;
		len++;
	}
	while (nb > 0)
	{
		nb /= nbase;
		len++;
	}
	return (len);
}


char	*ft_itoa_base(int nbr, int nbase)
{
	char	*base;
	char	*str;
	int	i;

	base = "0123456789abcdef";
	i = nbrlen(nbr, nbase);
	if (!(str = (char *) malloc(i + 1)))
		return (0);
	str[i--] = '\0';
	if (nbr == 0)
		str[0] = 48;
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		str[i] = base[nbr % nbase];
		nbr /= nbase;
		i--;
	}
	return (str);
}
