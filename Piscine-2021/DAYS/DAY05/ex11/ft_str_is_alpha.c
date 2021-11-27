#include <stdio.h>

int	ft_str_is_alpha(char *str);
int	main(void)
{
	printf("Empty : %s\n", ft_str_is_alpha("") ? "True" : "False");
	printf("achraf: %s\n", ft_str_is_alpha("achraf") ? "True" : "False");
	printf("1337  : %s\n", ft_str_is_alpha("1337") ? "True" : "False");
	return (0);
}

int	ft_str_is_alpha(char *str)
{
	while (*str)
	{
		if (!*str)
			return (1);
		else if ((*str >= 'a' && *str <= 'z') ||
			 (*str >= 'A' && *str <= 'Z'))
			str++;
		else
			return (0);
	}

	return (1);
}
