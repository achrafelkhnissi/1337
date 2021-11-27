#include <stdio.h>
#include <string.h>

char	*ft_strncat(char *dest, char *src, unsigned int n);

int	main(int argc, char *argv[])
{
	char	*dest = argv[1];
	char	*source = argv[2];
	int	i = argv[3][0] - '0';

	printf("before:\nSrc\t: %s\nDest\t: %s\n", source, dest);
	if (argc == 4)
		ft_strncat(dest, source, i);
	printf("After:\nSrc\t: %s\nDest\t: %s\n", source, dest);
	return (0);
}

char	*ft_strncat(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j] && j < n)
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (dest);
}

/*
char	*ft_strncat(char *dest, char *src, unsigned int n)
{
	while (*dest)
		dest++;

	while(*src && n--)
		*dest++ = *src++;

	*dest = '\0';

	return (dest);
}
*/
