#include "../includes/ft_hexdump.h"

int	ft_putstr(char *str, int index, int size, int flag)
{
	int	done;
	int	byte;
	int	i;

	byte = 0;
	done = 0;
	if (flag == 0)
		return (16);
	ft_putchar('|');
	while (byte < 16)
	{
		i = index + byte;
		if (str[i] == '\0')
		{
			done = 1;
			break;
		}
		if ((str[i] >= '!' && str[i] <= '~') || str[i] == ' ')
			ft_putchar(str[i]);
		else
			ft_putchar('.');
		byte++;
	}
	ft_putchar('|');
	if (done)
	{	
		ft_putchar('\n');
		ft_putaddr(size, flag);
		return (size);
	}
	return (byte);
}
