#include "ft_strdup.c"
#include <stdio.h>

int	main(void)
{
	char	*str;
	char	*copy;

	str = "Future is loading!";
	copy = ft_strdup(str);
	printf("copy: %s\n", copy);
	return (0);
}
