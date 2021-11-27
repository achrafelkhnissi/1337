int	ft_str_is_lowercase(char *str)
{
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			str++;
		else
			return (0);
	}

	return (1);
}

/*
 * or:
 *
 * if (*str < 'a' || *str > 'z')
 * 	return (0)
 *
 * str++;
 *
 */
