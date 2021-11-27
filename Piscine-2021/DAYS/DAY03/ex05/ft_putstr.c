#include <unistd.h>

void	ft_putstr(char *str);
int	main(void)
{
	ft_putstr("Future is loading, 1337!\n");

	return (0);
}

void	ft_putstr(char *str)
{
	int	i;
	i = 0;
	while(str[i] != '\0')
	{
		write(1, &str[i++], 1);
	}
}
