#include <stdio.h>
#include <string.h>

#define var_name(name) #name

int	check_base(char *base);
void	ft_putnbr_base(int nbr, char *base);

int	main(void)
{
	char	*hex = "0123456789ABCDEF";
	char	*dec = "0123456789";
	char	*oct = "012345678";
	char	*bin = "01";

	for (int i = -15; i < 16; i++)
	{
		ft_putnbr_base(i, hex);
		printf("\t| ");
		ft_putnbr_base(i, dec);
		printf("\t| ");
		ft_putnbr_base(i, oct);
		printf("\t| ");
		ft_putnbr_base(i, bin);
		printf("\n");
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	nbase;

	nbase = check_base(base);
	if (nbase >= 2 && nbase <= 16)
	{
		if (nbr < 0)
		{
			putchar('-');
			nbr = -nbr;
		}
		if (nbr >= nbase)
			ft_putnbr_base(nbr / nbase, base);
		putchar(base[nbr % nbase]);
	}
}		

int	check_base(char *base)
{
	char	*hex = "0123456789ABCDEF";
	char	*dic = "0123456789";
	char	*oct = "012345678";
	char	*bin = "01";

	if (strcmp(base, hex) == 0)
		return (16);
	else if (strcmp(base, dic) == 0)
		return (10);
	else if (strcmp(base, oct) == 0)
		return (8);
	else if (strcmp(base, bin) == 0)
		return (2);
	return (0);
}
