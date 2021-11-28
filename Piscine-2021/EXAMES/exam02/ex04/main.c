#include "print_bits.c"
#include "reverse_bits.c"

int	main(void)
{
	unsigned char c;

	c = '&';
	printf("ASCII: '%c', Dec Value: '%d'\n", c, c);
	print_bits(c);
	c = reverse_bits(c);
	printf("Reversed: \n");
	printf("ASCII: '%c', Dec Value: '%d'\n", c, c);
	print_bits(c);
	return (0);
}
