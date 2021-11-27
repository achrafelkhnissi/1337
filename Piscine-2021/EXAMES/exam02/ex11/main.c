#include "print_bits.c"

int	main(void)
{
	unsigned char c;

	c = '&';
	printf("ASCII: '%c', Dec Value: '%d'\n", c, c);
	print_bits(c);
	return (0);
}
