#include <unistd.h>

void	ft_putchar(char c);
void    ft_print_combn(int nb);
void	print_array(int arr[], int size);
int     check_array(int arr[], int size);
void	reset_array(int arr[], int size, int index);

int	main(void)
{
	ft_print_combn(9);
	return 0;
}

void    ft_print_combn(int nb)
{
	int size = nb;
	int arr[size];
	int index = size - 1;
	while(index >= 0)
	{
		arr[index] = index;
		index--;
	}

	index = 0;
	print_array(arr, size);
	while(arr[0] <= (10 - nb))
	{
		if(arr[size - 1] < 9)
		{
			arr[size - 1]++;
			print_array(arr, size);        
		}
		else
		{
			index = check_array(arr, size);
			if (index <= 0) break;
			reset_array(arr, size, index);
			print_array(arr, size);
		}
	}
	ft_putchar('\n');
}

void	print_array(int arr[], int size)
{
	int	i;
	i = 0;
	while(i < size)
	{
		ft_putchar(arr[i] + '0');
		i++;
	}
	if (check_array(arr, size) > 0)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

int 	check_array(int arr[], int size)
{
	int	index;
	index = size - 1;
	while (index >= 0 && arr[size - 1] == 9)
	{
		if (arr[index] == (arr[index - 1] + 1))
		{
			index--;
		}
		else
		{
		    break;
		}
	}
	return index;
}

void	reset_array(int arr[], int size, int index)
{
	int i;
	i = index - 1;
	arr[i]++;
	while (i < size - 1)
	{
		arr[i + 1] = arr[i] + 1;
		i++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
