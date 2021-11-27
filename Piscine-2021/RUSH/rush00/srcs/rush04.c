#include "ft_putchar.c"

void	rush03(int x, int y)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (i <= x && j <= y)
	{
		while (i <= x)
		{
			if (j == 1)
			{
				if (i == 1)
					ft_putchar('A');
				else if (i == x)
					ft_putchar('C');
				else
					ft_putchar('B');
			}
			else if (j == y)
			{
				if (i == 1)
					ft_putchar('C');
				else if (i == x)
					ft_putchar('A');
				else
					ft_putchar('B');
			}
			else
			{
				if (i == 1 || i == x)
					ft_putchar('B');
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

int	main(void)
{
	rush03(5, 3);
	ft_putchar('\n');
	rush03(5, 1);
	ft_putchar('\n');
	rush03(1, 1);
	ft_putchar('\n');
	rush03(1, 5);
	ft_putchar('\n');
	rush03(4, 4);
	return (0);
}
