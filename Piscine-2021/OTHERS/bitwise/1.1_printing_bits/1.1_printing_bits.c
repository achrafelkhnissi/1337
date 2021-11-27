/**********************************************************************
** 1.1 : Print bits
**********************************************************************/

/*
** This a vanilla question for interviews :
** Write a function that takes a byte, and prints it in binary
** Your function must be declared as follows:
** void	print_bits(unsigned char octet);
** Example, if you pass 2 to print_bits, it will print "00000010"
*/

#include "../bitwise.h"

/*
** First Method is standard while the second one use bitwise operators
*/

void	print_bits(unsigned char octet)
{
	int	i;

	i = 128;
	while (octet >= 0 && i)
	{
		(octet / i) ? write(1, "1", 1) : write(1, "0", 1);
		(octet / i) ? octet -= i : 0;
		i /= 2;
	}
}

void	print_bits2(unsigned char octet)
{
	int	i = 256;
	while (i >>= 1)
		(octet & i) ? write(1, "1", 1) : write(1, "0", 1);
}

int		main(void)
{
	int n = 64;
	print_bits(n);
	write(1, "\n", 1);
	print_bits2(n);
    write(1, "\n", 1);
}

