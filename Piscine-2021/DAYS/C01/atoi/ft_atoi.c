#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(char *str)
{
	int	number;
	int	sign;
	int	i;

	sign = 1;
	number = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||
		str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		number = (number * 10) + str[i++] - '0';
	return (number * sign);
}

int	main(void)
{
	printf("1337\t\t= %d\n", ft_atoi("1337"));		// > 1337
	printf("-1337\t\t= %d\n", ft_atoi("-1337"));		// > -1337
	printf(".\\n.1337\t= %d\n", ft_atoi(" \n 1337"));	// > 1337
	printf(".\\v.-1337\t= %d\n", ft_atoi(" \v -1337"));	// > -1337
	printf("-.1337\t\t= %d\n", ft_atoi("- 1337"));		// > 0
	printf("\\v.-.1337\t= %d\n", ft_atoi("\v - 1337"));	// > 0
	printf("+1337\t\t= %d\n", ft_atoi("+1337"));		// > 1337
	printf(".\\v.+1337\t= %d\n", ft_atoi(" \v +1337"));	// > 1337
	printf("1337ma\t\t= %d\n", ft_atoi("1337ma"));		// > 1337
	return (0);
}
