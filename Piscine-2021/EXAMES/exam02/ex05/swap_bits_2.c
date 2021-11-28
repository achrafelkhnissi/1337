#include <stdio.h>

unsigned char	swap_bits(unsigned char octet);

int	main(void)
{
	unsigned char	c;

	c = 20;
	c = swap_bits(c);
	printf("%c\n", c);
}

unsigned char	swap_bits(unsigned char octet)
{
	unsigned char result;

	result = ((octet << 4) & 0b11110000) | ((octet >> 4 ) & 0b00001111);
	return (result);
}
