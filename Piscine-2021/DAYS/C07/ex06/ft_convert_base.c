#include <stdlib.h>
#include <string.h>

int	check_base(char *base_to_check)
{
	char	*base;
	char	*lower_base;
	int	len;
	int	i;

	i = 0;
	len = 0;
	base = "0123456789abcdef";
	while (base_to_check[len])
		len++;
	lower_base = (char *) malloc(len + 1);
	while (base_to_check[i])
	{
		if (base_to_check[i] >= 'A' && base_to_check[i] <= 'Z')
			lower_base[i] = base_to_check[i] + ('a' - 'A');
		else
			lower_base[i] = base_to_check[i];
		i++;
	}
	if (!strncmp(base, lower_base, len))
		return (len);
	free(lower_base);
	return (-1);
}

int	nbrlen(int nb, int nbase)
{
	int	len;

	len = 0;
	if (nb < 0)
	{
		nb = -nb;
		len++;
	}
	while (nb > 0)
	{
		nb /= nbase;
		len++;
	}
	return (len);
}

char	*ft_itoa_base(int nbr, int nbase)
{
	char	*base;
	char	*str;
	int	i;

	base = "0123456789abcdef";
	i = nbrlen(nbr, nbase);
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
		str[i] = base[nbr % nbase];
		nbr /= nbase;
		i--;
	}
	return (str);
}

int	get_digit(char digit, int base)
{
	if (digit >= '0' && digit <= '9')
	{
		if ((digit - '0' ) >= base)
			return (-1);
		return (digit - '0');
	}
	else if (digit >= 'a' && digit <= 'f')
	{
		if ((digit + 10 - 'a') >= base)
			return (-1);
		return (digit + 10 - 'a');
	}
	else if (digit >= 'A' && digit <= 'F')
	{
		if ((digit + 10 - 'A') >= base)
			return (-1);
		return (digit + 10 - 'A');
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	base_n;
	int	sign;
	int	digit;
	int	n;
	int	i;

	n = 0;
	i = 0;
	sign = 1;
	digit = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	base_n = check_base(base);
	while (str[i] && base_n)
	{
		digit = get_digit(str[i++], base_n);
		if (digit < 0)
			return (-1);
		n = (n * base_n) + digit;
	}
	return (n * sign);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*result;
	int	base_f_len;
	int	base_t_len;
	int	int_nbr;

	base_f_len = check_base(base_from);
	base_t_len = check_base(base_to);
	if (!nbr || !base_f_len || !base_t_len)
		return (0);
	int_nbr = ft_atoi_base(nbr, base_from);
	result = ft_itoa_base(int_nbr, base_t_len);
	return (result);
}
