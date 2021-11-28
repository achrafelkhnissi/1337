#include "../includes/ft_hexdump.h"

void	ft_hexdump(char *content, unsigned int size, int flag)
{
	char	*str;
	unsigned int	i;

	str = content;
	i = 0;
	while(i < size)
	{

		ft_putaddr(i, flag);
		ft_puthex(str, i, flag);
		i += ft_putstr(str, i, size, flag);
		ft_putchar('\n');
	}
}
