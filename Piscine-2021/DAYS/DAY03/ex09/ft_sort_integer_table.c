#include <unistd.h>

#define SIZE 7

void	ft_putnbr(int n);
void	ft_putchar(char c);
void	ft_swap(int *a, int *b);
void	print_array(int *arr, int size);
void	ft_sort_int_tab(int *tab, int size);

int	main(void)
{
	int	arr[SIZE] = {8, 2, 4, 1, 0, 8, 2};

	print_array(arr, SIZE);
	ft_putchar('\n');
	ft_sort_int_tab(arr, SIZE);
	print_array(arr, SIZE);
	ft_putchar('\n');
	return (0);
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;

	i = size;
	while (--i)
	{
		if (tab[i] < tab[i - 1])
		{
			ft_swap(&tab[i], &tab[i - 1]);
			i = size;
		}
	}
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	print_array(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_putnbr(arr[i++]);
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
		ft_putnbr(n / 10);

	ft_putchar((n % 10) + '0');
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
