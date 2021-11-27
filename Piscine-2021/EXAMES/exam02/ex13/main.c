#include <stdio.h>
#include "ft_strrev.c"

int	main(void)
{
	char	str[] = "erutuF";

	printf("str = %s\n", str);
	ft_strrev(str);
	printf("rev = %s\n", str);
	return (0);
}
