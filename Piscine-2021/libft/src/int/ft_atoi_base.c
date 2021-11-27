#include "../../includes/libft.h"

char	to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return c + ('a' - 'A');
	return (c);
}

int	ft_lowstrncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (!n)
		return (0);
	while (s1[i] == to_lower(s2[i]) && s1[i] && s2[i] && i < n - 1)
		i++;
	return (s1[i] - to_lower(s2[i]));
}

int	check_base(char *base_to_check)
{
	char	*base;
	int	len;

	len = 0;
	base = "0123456789abcdef";
	while(base_to_check[len])
		len++;
	if (!ft_lowstrncmp(base, base_to_check, len))
		return (len);
	return (-1);
}

int	get_digit(char digit)
{
	if (digit >= '0' && digit <= '9')
		return (digit - '0');
	else if (digit >= 'a' && digit <= 'f')
		return (digit + 10 - 'a');
	else if (digit >= 'A' && digit <= 'F')
		return (digit + 10 - 'A');
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	base_n;
	int	sign;
	int	n;
	int	i;

	n = 0;
	i = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	base_n = check_base(base);
	while (str[i] && base_n)
			n = (n * base_n) + get_digit(str[i++]);
	return (n * sign);
}

