#ifndef BITWISE_H
# define BITWISE_H

#include <stdio.h>
#include <unistd.h>

void	showbits( unsigned int x )
{
	int	i;

	i = 0;
	printf("binary value: ");
	for (i = (sizeof(int) * 2) - 1; i >= 0; i--)
	{
		putchar(x & (1u << i) ? '1' : '0');
		if (i == 4) putchar(' ');
	}
	printf("\n");
}

/*
** Trick 1.4
*/

# define FLAG_A	1
# define FLAG_B	2
# define FLAG_C	4
# define FLAG_D	8

#endif
