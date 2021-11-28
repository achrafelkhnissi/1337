#include <stdio.h>

void	print_bits(unsigned int x)
{
	int	i;

	i = 0;
	for (i = (sizeof(int) * 2) - 1; i >= 0; i--)
		putchar(x & (1u << i) ? '1' : '0');
	printf("\n");
}
