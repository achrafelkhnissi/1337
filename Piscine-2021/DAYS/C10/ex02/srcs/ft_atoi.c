int	ft_atoi(char *str)
{
	int	number;
	int	sign;
	int	i;

	sign = 1;
	number = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'||
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
