#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max);

int	main(void)
{
	int	*arr;
	int	i;

	i = 0;
	arr = ft_range(10, 30);
	while (i < 20)
		printf("%d ", arr[i++]);
	putchar('\n');
	return (0);
}

int	*ft_range(int min, int max)
{
	int	len;
	int	*range;
	int	i;

	if (min >= max)
		return (0);
	i = 0;
	len = max - min;
	range = (int *) malloc(len * 4);
	if (!range)
		return (NULL);
	while (i < len && min < max)
		range[i++] = min++;
	return (range);
}

/*
int	*ft_range(int min, int max)
{
	int *p;
	int i;

	if (min >= max)
		return (0);
	p = malloc(max - min);
	if (p == NULL)
		return (0);
	i = 0;
	while (min < max)
	{
		p[i] = min;
		i++;
		min++;
	}
	return (p);
}
*/
