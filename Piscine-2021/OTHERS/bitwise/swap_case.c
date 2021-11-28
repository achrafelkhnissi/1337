#include <stdio.h>

/* Assuming "c" is a character! */
char	swap_case(char c)
{
	return (c ^ 32);
}

char	check_case(char c)
{
	return (((c >> 5) & 1)  ? '0' : '1');
}

char	to_lower(char c)
{
	return c | 32;
}

char	to_upper(char c)
{
	return (c & ~32);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		printf("swap_case\t= %c\n", swap_case(*av[1]));
		printf("check_case\t= %c\n", check_case(*av[1]));
		printf("to_lower\t= %c\n", to_lower(*av[1]));
		printf("to_upper\t= %c\n", to_upper(*av[1]));
	}
	return (0);
}
