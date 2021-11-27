#include <stdio.h>

char	*ft_strupcase(char *str);
int	main(void)
{
	char	name[] = "Future is loading!.";

	printf("lowercase: %s\n", name);
	printf("uppercase: %s\n", ft_strupcase(name));
	return (0);
}

char	*ft_strupcase(char *str)
{
	int	i;
	
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return (str);
}
