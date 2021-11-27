#include <unistd.h>

void    ft_putchar(char c)
{
        write(1, &c, 1);
}

void	ft_print_numbers(void)
{
	char	l;

	l = '0';

	while (l <= '9')
	{
		ft_putchar(l++);
	}
}

int     main(void)
{
	ft_print_numbers();
        ft_putchar('\n');

        return 0;
}
