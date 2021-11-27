#include <stdio.h>
#include "ft_convert_base_v2.c"

int	main(int argc, char **argv)
{
	if (argc == 4)	
	{
		char	*result;
		result = ft_convert_base(argv[1], argv[2], argv[3]);
		printf("result = %s\n", result);
		free(result);
	}
	return (0);
}
