#include "../includes/ft_hexdump.h"

void     ft_puthex(char *str, int index, int flag)
{
	char	*hex = "0123456789abcdef";

	int	byte = 0;
	while (byte < 16)
	{
		if (str[byte + index] == '\0')
			write(STDOUT_FILENO, "  ", 2);
		else if (str[byte] > 16)
		{
				ft_putchar(hex[str[byte + index] / 16]);
				ft_putchar(hex[str[byte + index] % 16]);	
		}
		else
		{
				ft_putchar('0');
				ft_putchar(hex[str[byte + index] % 16]);
		}
		byte++;
		ft_putchar(' ');
		if (byte == 8 && flag)
			write(STDOUT_FILENO, " ", 1);
	}
	if (flag)
		ft_putchar(' ');
}
