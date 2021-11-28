#include "ft_strcmp.c"
#include <stdio.h>

int	main(void)
{
	char	*s1;
	char	*s2;

	s1 = "Hollow";
	s2 = "World";
	printf("s1 = %s\ns2 = %s\n", s1, s2);
	printf("result = %d\n", ft_strcmp(s1, s2));
	return (0);
}
