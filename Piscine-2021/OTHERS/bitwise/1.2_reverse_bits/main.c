#include <stdio.h>
#include "../bitwise.h"
#include "1st_method.c"
#include "2nd_method.c"
#include "3rd_method.c"

int	main(void)
{
	unsigned char c;

	c = '.';
	printf("ASCII: '%c', Dec Value: '%d'\n", c, c);
	showbits(c);
	//c = rev_bits1(c);
	//c = rev_bits2(c);
	c = rev_bits3(c);
	printf("Reversed: \n");
	printf("ASCII: '%c', Dec Value: '%d'\n", c, c);
	showbits(c);
	return (0);
}
