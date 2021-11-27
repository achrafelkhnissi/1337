#include "../../includes/libft.h"

void	puthex(char c)
{
	char	*hex = "0123456789abcdef";

	ft_putchar('\\');
	if (c > 16)
	{
		ft_putchar(hex[c / 16]);
		ft_putchar(hex[c % 16]);	
	}
	else
	{
		ft_putchar('0');
		ft_putchar(hex[c % 16]);
	}
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= '!' && str[i] <= '~') || str[i] == ' ')
			ft_putchar(str[i++]);
		else
			puthex(str[i++]);
	}	
}
