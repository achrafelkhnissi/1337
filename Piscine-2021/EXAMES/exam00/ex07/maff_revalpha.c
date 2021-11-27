#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(void)
{
	int	l;

	l = 122;
	while (l >= 97)
	{
		if (l % 2 == 0)
			ft_putchar(l);
		else
			ft_putchar(l - 32);
		l--;
	}
	write(1, "\n", 1);
	return (0);
}
