#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int	x;

	x = 10;
	while (x --> 0)
		printf("x = %d\n", x);
	printf("sizeof(x) = %lu\n", sizeof(&x));
	return (0);
}
