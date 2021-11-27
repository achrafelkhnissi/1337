#include "ft_putchar.c"

void	rush00(int x, int y)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (i <= x && j <= y)
	{
		while (i <= x)
		{
			if (j == 1 || j == y)
			{
				if (i == 1 || i == x)
					ft_putchar('o');
				else
					ft_putchar('-');
			}
			else
			{
				if (i == 1 || i == x)
					ft_putchar('|');
				else
					ft_putchar(' ');
			}
			i++;
		}
		ft_putchar('\n');
		i = 1;
		j++;
	}
}
