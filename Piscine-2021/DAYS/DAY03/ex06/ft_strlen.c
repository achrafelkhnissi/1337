#include <unistd.h>

void	ft_putnbr(int n);
void	ft_putchar(char c);
int	ft_strlen(char *str);
int	main(void)
{
	char	*string;
	int	length;

	string = "Future is loading, 1337!";
	length = ft_strlen(string);

	ft_putnbr(length);
	ft_putchar('\n');

	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;

	while (str[i] != '\0')
	{
		i++;
	}

	return (i);
}

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}

	if (n > 9)
	{
		ft_putnbr(n / 10);
	}

	ft_putchar((n % 10) + '0');
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
