#include <ctype.h>

int	ft_atoi(const char *str)
{
	int	nb;
	int	sign;
	int	i;

	nb = 0;
	sign = 1;
	i = 0;
	while (isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + str[i] - '0';
		i++;
	}
	return (nb * sign);
}
