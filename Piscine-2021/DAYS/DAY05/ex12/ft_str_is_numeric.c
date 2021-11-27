#include <stdio.h>

int	ft_str_is_numeric(char *str);
int	main(void)
{
	printf("Empty\t: %s\n", ft_str_is_numeric("") ? "True" : "False");
	printf("achraf\t: %s\n", ft_str_is_numeric("achraf") ? "True" : "False");
	printf("1337\t: %s\n", ft_str_is_numeric("1337") ? "True" : "False");

	return (0);
}

int	ft_str_is_numeric(char *str)
{
	while(*str)
	{
		if (!*str)
			return (1);
		else if (*str >= '0' && *str <= '9')
			str++;
		else
			return (0);
	}

	return (1);
}
