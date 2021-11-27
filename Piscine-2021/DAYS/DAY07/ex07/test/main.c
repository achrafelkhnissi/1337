#include <stdio.h>
#include "split.c"

int	main(void)
{
	char	**str;
	char	*s1;
	char	*saperator;
	int	i;

	i = 0;
	s1 = "Future is loading!";
	saperator = "is";
	str = ft_split(s1, saperator);
	while (str[i])
		printf("str[%d] = %s\n", i, str[i]), i++;
	return (0);
}
