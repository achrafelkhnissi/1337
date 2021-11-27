#include <unistd.h>
#include <stdio.h>

#define SIZE 7

void	ft_putnbr(int c);
void	ft_putchar(char c);
void	ft_swap(int *a, int *b);
void	print_array(int *tab, int size);
void	ft_rev_int_tab(int *tab, int size);
int	main(void)
{
	int	arr[SIZE] = {1, 2, 3, 4, 5, 6, 7};

	print_array(arr, SIZE);
	printf("\n");

	ft_rev_int_tab(arr, SIZE);

	print_array(arr, SIZE);
	printf("\n");

	return (0);
}

void	ft_rev_int_tab(int *tab, int size)
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

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	print_array(int *tab, int size)
{
	int	i;

	i = 0;

	while (i < size)
	{
		ft_putnbr(tab[i++]);
		if (i < size)
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
	}
}

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}

	if (n > 9)
	{
		ft_putnbr(n / 10);
	}

	ft_putchar((n % 10) + '0');
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
