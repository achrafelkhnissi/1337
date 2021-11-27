#include <unistd.h>

void	ft_putchar(char c);
void	ft_print_comb2(void);
int	main(void)
{
	ft_print_comb2();

	return (0);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;

	while (a < 99)
	{
		b = a + 1;
		while (b <= 99)
		{
			ft_putchar((a / 10) + '0');
			ft_putchar((a % 10) + '0');
			
			ft_putchar(' ');
			
			ft_putchar((b / 10) + '0');
			ft_putchar((b % 10) + '0');
			
			if (a < 98)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}

			b++;
		}
		a++;
	}
	ft_putchar('\n');
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
