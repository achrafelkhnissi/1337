#include <stdio.h>

int	ft_str_is_uppercase(char *str);
int	main(void)
{
	printf("Lowrcase\t: %s\n", ft_str_is_uppercase("achraf") ? "True" : "False");
	printf("Uppercase\t: %s\n", ft_str_is_uppercase("KHNISSI") ? "True" : "False");
	printf("Bothcase\t: %s\n", ft_str_is_uppercase("FurueIsLoading") ? "True" : "False");
	printf("Withspaces\t: %s\n", ft_str_is_uppercase("achraf el khnissi") ? "True" : "False");
	printf("Numeric  \t: %s\n", ft_str_is_uppercase("1337") ? "True" : "False");

	return (0);
}

int	ft_str_is_uppercase(char *str)
{
	while (*str)
	{
		if (*str < 'A' || *str > 'Z')
			return (0);
		str++;
	}

	return (1);
}
