#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc > 1)
		while (*argv[1])
			write(1, argv[1]++, 1);
	write(1, "\n", 1);
	return (0);
}
