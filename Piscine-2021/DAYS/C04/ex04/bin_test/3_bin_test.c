#include <stdio.h>

void	putbin(int n)
{
	char	*bin = "01";
	static	int	neg, pos;

	if (n < 0)
		n = -n, neg = 1;
	else pos = 1;
	
	if (neg)
	{
		putchar('1');
		neg = 0;
	}
	else if (pos)
	{
		putchar('0');
		pos = 0;
	}

	if (n >= 2)
		putbin(n / 2);

	putchar(bin[n % 2]);
}

int	main(void)
{
	for (int i = -15; i < 16; i++)
	{
		putbin(i);
		putchar('\n');
	}
	return (0);
}
