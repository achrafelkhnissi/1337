#include <stdio.h>

int     puthex(char *str, int index)
{
	char	*hex = "0123456789abcdef";

	int     done = 0;
	int	byte = 0;

    while (byte < 16 || !done)
    {
        if (str[byte + index] == '\0') 
            done = 1;

        if (byte == 16) break;

    	    if (byte % 2 == 0)
	    	    putchar(' ');

    	    if (str[byte] > 16)
	        {
	        	putchar(hex[str[byte + index] / 16]);
		        putchar(hex[str[byte + index] % 16]);	
        	}
	        else
	        {
		        putchar('0');
    		    putchar(hex[str[byte + index] % 16]);
	        }
	        byte++;
    }
    if (done) return (999);

    return (byte);
}

int	main(void)
{
	char	*str = "Future\nis loading.. 1337!";
    
    int i = 0;
    while (i < 116)
    {
        i += puthex(str, i);
        putchar('\n');
        if (i < 0) break;
    }

	return (0);
}

