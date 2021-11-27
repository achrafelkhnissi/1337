#include <unistd.h>

void	ft_putchar(char c);
void	ft_is_negative(int n);

int     main(void)
{
	ft_is_negative(1337);
        ft_putchar('\n');

        return 0;
}

void    ft_putchar(char c)
{
        write(1, &c, 1);
}

void	ft_is_negative(int n)
{
	if (n > 0)
	{
		ft_putchar('P');
	}
	else
	{
		ft_putchar('N');
	}
}
