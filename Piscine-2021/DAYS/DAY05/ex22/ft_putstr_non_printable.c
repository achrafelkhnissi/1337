#include <stdio.h>
#include <string.h>

void	puthex(char c);
void	ft_putstr_non_printable(char *str);

int	main(void)
{
	char	*str = "Coucou\ntu vas bien ?";

	printf("Original: %s\n", str);
	printf("New one : ");
	ft_putstr_non_printable(str);
	putchar('\n');
	return (0);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= '!' && str[i] <= '~') || str[i] == ' ')
			putchar(str[i++]);
		else
			puthex(str[i++]);
	}	
}

void	puthex(char c)
{
	char	*hex = "0123456789abcdef";

	putchar('\\');
	if (c > 16)
	{
		putchar(hex[c / 16]);
		putchar(hex[c % 16]);	
	}
	else
	{
		putchar('0');
		putchar(hex[c % 16]);
	}
}
