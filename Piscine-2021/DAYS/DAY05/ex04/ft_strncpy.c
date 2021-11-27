#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n);
int	main(void)
{
	char	array2[6];
	ft_strncpy(array2, "abcdefgh", 6);
	printf("ca: %s\n", array2);
	return (0);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
		dest[i++] = '\0';
	return (dest);
}
