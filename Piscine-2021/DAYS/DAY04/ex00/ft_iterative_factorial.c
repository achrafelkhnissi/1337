#include <stdio.h>

int	facto(int nb)
{
	int	facto;

	facto = 1;
	if (nb < 0)
		return 0;
	while (nb)
		facto = facto * (nb--);

	return (facto);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		printf("%s! = %d\n", argv[1], facto(argv[1][0] - '0'));
	return (0);
}
