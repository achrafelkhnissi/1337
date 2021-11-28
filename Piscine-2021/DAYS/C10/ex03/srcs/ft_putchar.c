#include "../includes/ft_hexdump.h"

void	ft_putchar(char c)
{
	write(STDOUT_FILENO, &c, 1);
}
