#include <stdio.h>
#include <string.h>

void	ft_swap(char *a, char *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_rev_int_tab(char *tab, int size)
{
	int	start;
	int	end;
	int	middle;

	start = 0;
	end = size - 1;
	middle = end / 2;

	while (start <= middle)
	{
		ft_swap(&tab[start++], &tab[end--]);
	}
}

void    putbin(int n)
{
	//TODO: negative with two complement.

	char	*bin = "01";
	char	n_bin[32] = "00000000000000000000000000000000";
	int	n_size;

	if (n <= 255)
		n_size = 8;
	else if(n <= 65536)
		n_size = 16;
	else if (n <= 16777215)
		n_size = 24;
	else
		n_size = 32;

	int i = 0;
	int neg = 0;

	if (n < 0) neg = 1, n = -n;

	while (n)
	{
		n_bin[i++] = bin[n % 2];
		n /= 2;
	}

	//if (neg)
	for (i = 0; i < n_size; i++) putchar(n_bin[i]);
	/*else
	{
		ft_rev_int_tab(n_bin, 8);
		for (i = 0; i < n_size; i++) 
		{
			//if (i == 4) putchar(' ');
			putchar(n_bin[i]);
		}
	}*/
}

int	main(void)
{

	for (int i = 0; i < 1111; i++)
	{
		putbin(i);
		putchar('\n');
	}
    
    return (0);
}
