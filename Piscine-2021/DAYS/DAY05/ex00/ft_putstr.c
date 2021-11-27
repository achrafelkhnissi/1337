#include <stdio.h>

void	ft_putstr(char *str);
int	main(void)
{
	ft_putstr("Future is loading!\n");
}

void	ft_putstr(char *str)
{
	while (*str)
		putchar(*str++);
}
