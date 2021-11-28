#include <stdio.h>

static int count;

void    putbin(int n)
{
	char	*bin = "01";
	int i;
	int n_size;
    static int neg;
    
    if (n < 0) n = -n, neg++;

	if (n <= 255)
		n_size = 8;
	else if(n <= 65536)
		n_size = 16;
	else if (n <= 16777215)
		n_size = 24;
	else
		n_size = 32;
	
    char    n_bin[n_size];

    for (i = 0; i < n_size; i++) n_bin[i] = '0';
    n_bin[n_size] = '\0';
    
	while (n)
	{
		n_bin[i++] = bin[n % 2];
		n /= 2;
	}
	
	for (i = 0; i < n_size; i++) putchar(n_bin[i]);

/*
    if (neg)
	    for (i = 0; i < n_size; i++) putchar(n_bin[i]);
	else
	{
		ft_rev_int_tab(n_bin, 8);
		for (i = 0; i < n_size; i++) 
		{
			//if (i == 4) putchar(' ');
			putchar(n_bin[i]);
		}
	}
*/
}


int	main(void)
{
    for (int i = 0; i < 16; i++)
    {
        putbin(i);
        putchar('\n');
    }
    return (0);
}
