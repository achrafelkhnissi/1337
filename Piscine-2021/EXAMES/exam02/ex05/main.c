#include "print_bits.c"
#include "swap_bits.c"

int	main(void)
{
	unsigned char c;

	c = 65;
	printf("ASCII: '%c', Dec Value: '%d'\n", c, c);
	print_bits(c);
	c = swap_bits(c);
	printf("Swapped: \n");
	printf("ASCII: '%c', Dec Value: '%d'\n", c, c);
	print_bits(c);
	return (0);
}
