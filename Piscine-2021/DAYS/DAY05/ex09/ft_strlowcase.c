#include <stdio.h>

char	*ft_strlowcase(char *str);
int	main(void)
{
	char	future[] = "FUTURE IS LOADING!";

	printf("Uppercase: %s\n", future);
	printf("Lowercase: %s\n", ft_strlowcase(future));
	return (0);
}

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}
