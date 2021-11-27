#include <stdio.h>

void    print_bits(unsigned char octet)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		putchar((octet & 128) ? '1' : '0');
		octet <<= 1;
		bit++;
	}
	putchar('\n');
}
