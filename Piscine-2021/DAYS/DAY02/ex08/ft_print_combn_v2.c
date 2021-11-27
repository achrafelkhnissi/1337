#include <unistd.h>

void	ft_putchar(char c);
void	ft_print_combn(int n);
void	print_arr(int *arr, int size);
void	reset_arr(int *arr, int size, int index);
int	check_arr(int *arr, int size);
int	main(int argc, char **argv)
{
	if(argc == 2)
		ft_print_combn(argv[1][0] - '0');

	return (0);
}

void	ft_print_combn(int n)
{
	int	arr[n];
	int	i;

	i = 0;
	while (i < n)
	{
		arr[i] = i;
		i++;
	}
	
	i = 0;
	while (arr[0] <= 10 - n)
	{
		if (arr[n - 1] < 9)
		{
			print_arr(arr, n);
			arr[n - 1]++;
		}
		else
		{
			print_arr(arr, n);
			i = check_arr(arr, n);
			if (i < 0) break;
			reset_arr(arr, n, i);
		}
	}
}

int	check_arr(int *arr, int size)
{
	int	i;
	i = size - 1;
	i--;
	while (arr[size - 1] == 9)
	{
		if (arr[i] == arr[i + 1] - 1) i--;
		else return (i);
	}
	return (i);
}

void	reset_arr(int *arr, int size, int index)
{
	arr[index]++;
	while (index < size - 1)
	{
		arr[index + 1] = arr[index] + 1;
		index++;
	}
}

void	print_arr(int *arr, int size)
{
	int	i;
	
	i = 0;
	
	while (i < size)
	{
		ft_putchar(arr[i++] + '0');
	}
	if (arr[0] < 10 - size)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
	else
	{
		ft_putchar('\n');
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
