#include <stdio.h>

int	ft_str_is_printable(char *str);
int	main(void)
{
	int	i;

	i = 0;

	while (++i < 128)
		printf("%c = %s\n", i, ft_str_is_printable((char *) &i) ? "Printable." : "None printable");

	return (0);
}

int	ft_str_is_printable(char *str)
{
	while (*str)
	{
		if (*str < '!' || *str > '~')
			return (0);
		str++;
	}

	return (1);
}
