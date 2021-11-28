#include <unistd.h>
#include <stdio.h>

void	convert_hexa(unsigned char c)
{
	write(1, &"0123456789abcdef"[c / 16], 1);
	write(1, &"0123456789abcdef"[c % 16], 1);
}

int	main(void)
{
	char	*addr = "test";
	int	j = 56;

	printf("without printf: ");
	for (int i = 0; i < 8; i++)
		convert_hexa((unsigned long) addr >> 8), j -= 8;
	putchar('\n');

	printf("\nwith printf: %p\n", addr);

	return (0);
}

/*
 * notes;
 * 1. printing addr gives the number 83
 * 2. passing addr with >> 8 (shiftin bites i guess)
 * 	then decrementing j - 8
 * 	gives the address;
 * 3. reversing the process gives the address reversed.
 * 
 */
