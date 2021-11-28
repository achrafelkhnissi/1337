#include "is_power_of_2.c"
#include <stdio.h>

int	main(void)
{
	unsigned int	nb;

	nb = 0;
	while (nb++ < 100)
		if (is_power_of_2(nb))
			printf("nb %d is power of 2\n", nb);
	return (0);
}
