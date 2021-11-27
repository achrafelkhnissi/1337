#include <stdlib.h>
#include <stdio.h>

char	*ft_itoa(int nbr)
{
	char	*str;
	int	copy;
	int	i;

	i = 0;
	copy = nbr;
	while (i++ < copy)
		copy /= 10;
	printf("i = %d\n", i);
	if (!(str = (char *) malloc(i + 1)))
		return (0);
	str[i--] = '\0';
	if (nbr == 0)
		str[0] = 48;
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		str[i] = '0' + (nbr % 10);
		nbr /= 10;
		i--;
	}
	return (str);
}

int	main(void)
{
	char	*str;
	int	nb;
	int	i;

	nb = 1337;
	i = 0;
	str = ft_itoa(nb);
	while (str[i])
		putchar(str[i++]);
	putchar('\n');
	return (0);
}

