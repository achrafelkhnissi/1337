int	ft_str_is_numeric(char *str)
{
	while(*str)
	{
		if (!*str)
			return (1);
		else if (*str >= '0' && *str <= '9')
			str++;
		else
			return (0);
	}

	return (1);
}
