#include "../../includes/libft.h"

int	check_base(char *base)
{
	char	*hex = "0123456789ABCDEF";
	char	*dic = "0123456789";
	char	*oct = "012345678";
	char	*bin = "01";

	if (ft_strcmp(base, hex) == 0)
		return (16);
	else if (ft_strcmp(base, dic) == 0)
		return (10);
	else if (ft_strcmp(base, oct) == 0)
		return (8);
	else if (ft_strcmp(base, bin) == 0)
		return (2);
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
			ft_putchar('-');
			nbr = -nbr;
		}
		if (nbr >= nbase)
			ft_putnbr_base(nbr / nbase, base);
		ft_putchar(base[nbr % nbase]);
	}
}		
