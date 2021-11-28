#include <stdio.h>

void	ft_foreach(int *tab, int length, void(*f)(int));
void	ft_putnbr(int nb);

int	main(void)
{
	int	arr[4] = {1, 3, 3, 7};

	ft_foreach(arr, 4, &ft_putnbr);
	return (0);
}

void	ft_foreach(int *tab, int length, void(*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
		f(tab[i++]);
	putchar('\n');
}

void	ft_putnbr(int nb)
{
	printf("%d", nb);
}
