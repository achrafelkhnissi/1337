#include <stdio.h>

int	putstr(char *str, int index)
{
	int	done;
	int	byte;

	byte = 0;
	done = 0;

	while (str[byte] || byte < 16)
	{
		if (str[byte + index] == '\0') done = 1;
		if (byte == 16) break;
		
		if ((str[byte + index] >= '!' && str[byte + index] <= '~') || str[byte + index] == ' ')
			putchar(str[byte + index]);
		else
			putchar('.');
		byte++;
	}

	if (done) return (9999);
	return (index + byte);
}

int	main(void)
{
	char	*str = "Future\nis loading.. 1337!";
    
    int i = 0;
    while (i < 116)
    {
        i = putstr(str, i);
        putchar('\n');
        if (i < 0) break;
    }

	return (0);
}

