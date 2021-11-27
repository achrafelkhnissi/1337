#include <unistd.h>

void	ft_putchar(char c);
int	check_arr(int *arr, int size);
void	print_arr(int *arr, int size);
void	reset_arr(int *arr, int size, int i);
void	ft_print_combn(int n);

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_print_combn(argv[1][0] - '0');

	return (0);
}

void	ft_print_combn(int n)
{
	int	nb[n];
	int	i;

	i = 0;
	while (i < n)
	{
		nb[i] = i;
	       	i++;
	}

	while (nb[0] <= 10 - n)
	{
		if (nb[n - 1] < 9)
		{
			print_arr(nb, n);
			nb[n- 1]++;
		}
		else
		{
			print_arr(nb, n);
			i = check_arr(nb, n);
			if (i < 0)
				break;
			reset_arr(nb, n, i);
		}
	}
}

void	reset_arr(int *arr, int size, int i)
{
	arr[i]++;

	while (i++ <= size - 1)
		arr[i] = arr[i - 1] + 1;
}

int	check_arr(int *arr, int size)
{
	while(--size)
		if (arr[size] != arr[size - 1] + 1)
			break;
	return (size - 1);
}

void	print_arr(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
		ft_putchar(arr[i++] + '0');
	if (arr[0] < 10 - size)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
	else
		ft_putchar('\n');
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
