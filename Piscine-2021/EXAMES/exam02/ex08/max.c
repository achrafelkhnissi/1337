#include <stdio.h>

int	max(int* tab, unsigned int len);

int	main(void)
{
	int	arr[8] = {1, 23, 13, 4, 34, 45, 20, 100};

	printf("Largest = %d\n", max(arr, 8));
	return (0);
}

int	max(int* tab, unsigned int len)
{
	int	largest;
	unsigned int	i;

	largest = 0;
	i = 0;
	while (i < len)
	{
		if (tab[i] > largest)
			largest = tab[i];
		i++;
	}
	return (largest);
}
