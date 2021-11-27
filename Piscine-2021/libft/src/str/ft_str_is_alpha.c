int	ft_str_is_alpha(char *str)
{
	while (*str)
	{
		if (!*str)
			return (1);
		else if ((*str >= 'a' && *str <= 'z') ||
			 (*str >= 'A' && *str <= 'Z'))
			str++;
		else
			return (0);
	}

	return (1);
}
