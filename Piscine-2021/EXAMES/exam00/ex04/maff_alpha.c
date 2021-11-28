#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(void)
{
	int	l;

	l = 97;
	while (l <= 122)
	{
		if (l % 2 == 0)
			ft_putchar(l - 32);
		else
			ft_putchar(l);
		l++;
	}
	ft_putchar('\n');
	return (0);
}
