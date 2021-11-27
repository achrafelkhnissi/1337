#include <unistd.h>

void	ft_putchar(char c);
void	ft_print_comb2(void);
void	ft_print_numbers(int x, int y);

int	main(void)
{
	ft_print_comb2();

	return 0;
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_numbers(int x, int y)
{
	ft_putchar((x / 10) + '0');
	ft_putchar((x % 10) + '0');
	ft_putchar(' ');
	ft_putchar((y / 10) + '0');
	ft_putchar((y % 10) + '0');
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;

	while(i <= 98)
	{
		j = i + 1;
		while (j <= 99)
		{
			ft_print_numbers(i, j);
			if(i != 98)
			{	
				ft_putchar(',');
				ft_putchar(' ');
			}
			j++;
		}
		i++;
	}
	ft_putchar('\n');
}
