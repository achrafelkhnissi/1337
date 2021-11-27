#include <stdio.h>

char	*ft_strcat(char *dest, char *src);
int	main(int argc, char *argv[])
{
	char	*dest = argv[1];
	char	*source = argv[2];

	printf("before:\nSrc\t: %s\nDest\t: %s\n", source, dest);
	if (argc == 3)
		ft_strcat(dest, source);
	printf("After:\nSrc\t: %s\nDest\t: %s\n", source, dest);
	return (0);
}

char	*ft_strcat(char *dest, char *src)
{
	int	d;
	int	s;

	d = 0;
	s = 0;
	while (dest[d])
		d++;
	while (src[s])
		dest[d++] = src[s++];
	dest[d] = '\0';
	return (dest);
}

/*
 * V2:
   	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (dest);
*/
