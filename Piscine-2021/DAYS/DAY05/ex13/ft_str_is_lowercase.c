#include <stdio.h>

int	ft_str_is_lowercase(char *str);
int	main(void)
{
	printf("Lowrcase\t: %s\n", ft_str_is_lowercase("achraf") ? "True" : "False");
	printf("Uppercase\t: %s\n", ft_str_is_lowercase("KHNISSI") ? "True" : "False");
	printf("Bothcase\t: %s\n", ft_str_is_lowercase("FurueIsLoading") ? "True" : "False");
	printf("Withspaces\t: %s\n", ft_str_is_lowercase("achraf el khnissi") ? "True" : "False");
	printf("Numeric  \t: %s\n", ft_str_is_lowercase("1337") ? "True" : "False");

	return (0);
}

int	ft_str_is_lowercase(char *str)
{
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			str++;
		else
			return (0);
	}

	return (1);
}

/*
 * or:
 *
 * if (*str < 'a' || *str > 'z')
 * 	return (0)
 *
 * str++;
 *
 */
