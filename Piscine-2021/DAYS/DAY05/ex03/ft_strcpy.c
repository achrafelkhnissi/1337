#include <stdio.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	main(void)
{
	char number1[] = "1337";
	char number2[] = "";

	ft_strcpy(number2, number1);
	printf("%s\n", number2);
	return (0);
}
