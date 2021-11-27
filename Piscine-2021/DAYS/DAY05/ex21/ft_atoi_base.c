#include <stdio.h>

char	to_lower(char c);
int	get_digit(char digit);
int	check_base(char *base);
int	ft_atoi_base(char *str, char *base);
int	ft_lowstrncmp(char *s1, char *s2, unsigned int n);

int	main(void)
{
	char	*hex = "0123456789abcdef";
	char	*dec = "0123456789";
	char	*oct = "012345678";
	char	*bin = "01";

	printf("hex -1337 = %d\n", ft_atoi_base("-1337", hex));
	printf("bin -1111 = %d\n", ft_atoi_base("-1111", bin));
	printf("dec -1337 = %d\n", ft_atoi_base("-1337", dec));
	printf("oct -1337 = %d\n", ft_atoi_base("-1337", oct));
	return (0);
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

int	check_base(char *base_to_check)
{
	char	*base;
	int	len;

	len = 0;
	base = "0123456789abcdef";
	while (base_to_check[len])
		len++;
	if (!ft_lowstrncmp(base, base_to_check, len))
		return (len);
	return (-1);
}

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

