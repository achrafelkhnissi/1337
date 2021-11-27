#include <unistd.h>

void	ft_print_comb(void);
void	ft_putchar(char c);
int	main(void)
{
	ft_print_comb();

	return (0);
}

void	ft_print_comb(void)
{
	int	a;
	int	b;
	int	c;

	a = '0';

	while (a <= '7')
	{
		b = a + 1;
		while (b <= '8')
		{
			c = b + 1;
			while (c <= '9')
			{
				ft_putchar(a);
				ft_putchar(b);
				ft_putchar(c++);
				
				if (a < '7')
				{
					ft_putchar(',');
					ft_putchar(' ');
				}
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
