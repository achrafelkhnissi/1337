#include "../bitwise.h"

void	showbits( unsigned int x )
{
	int	i;

	i = 0;
	printf("binary value: ");
	for (i = (sizeof(int) * 2) - 1; i >= 0; i--)
	{
		putchar(x & (1u << i) ? '1' : '0');
	}
	printf("\n");
	printf("\n");
}

int	main(void)
{
	int	thirty_two_bits;
	unsigned char   one_byte;

	thirty_two_bits = 3; // 1)
	one_byte = 46;

	printf("32 byte: \n");
	printf("Value: %u\n", thirty_two_bits);
	showbits(thirty_two_bits);
	printf("after '<<= 1': %u\n", thirty_two_bits <<= 1 ); // 2
	showbits(thirty_two_bits);
	printf("after '>>= 1': %u\n", thirty_two_bits >>= 1);
	showbits(thirty_two_bits);
	printf("after '&= 1': %u\n", thirty_two_bits &= 1);
	showbits(thirty_two_bits);

	//one_byte = 46; // reminder
	printf("1 byte: \n");
	printf("value : %d\n", one_byte);
	showbits(one_byte);
	printf("after '|= 1': %d\n", one_byte |= 1);
	showbits(one_byte);
	printf("after '&= ~1': %d\n", one_byte &= ~1);
	showbits(one_byte);
	//one_byte ^= 0b11010000; // 7) 00101110 = 00101110 ^ 11010000
	printf("after '001011110 ^= 11010000': %d\n", one_byte ^= 0b11010000);
	showbits(one_byte);
	return (0);
}
