#include "ft_putchar.c"

void	print_edges(int i, int j, int x, int y)
{
	if (j == 1)
	{
		if (i == 1)
			ft_putchar('/');
		else if (i == x)
			ft_putchar('\\');
		else
			ft_putchar('*');
			
	}
	else if (j == y)
	{
		if (i == 1)
			ft_putchar('\\');
		else if	(i == x)
			ft_putchar('/');
		else
			ft_putchar('*');
	}
}

void	rush01(int x, int y)
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
				print_edges(i, j, x, y);
			else
			{
				if (i == 1 || i == x)
					ft_putchar('*');
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
	rush01(5, 3);
	rush01(5, 1);
	rush01(1, 1);
	rush01(1, 5);
	rush01(4, 4);
	return (0);
}
