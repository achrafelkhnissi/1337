#include <stdlib.h>

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

int	ft_atoi_base(char *str, int base_n)
{
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
	while (str[i])
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
	char	*base;
	int	f_len;
	int	t_len;

	f_len = 0;
	t_len = 0;
	base = "0123456789abcdef";
	while (base_from[f_len])
	{
		if (!(base_from[f_len] == base[f_len]))
			return (NULL);
		f_len++;
	}
	while (base_to[t_len])
	{
		if(!(base_to[t_len] == base[t_len]))
			return (NULL);
		t_len++;
	}
	if (!nbr || !base_from || !base_to)
		return (0);
	result = ft_itoa_base(ft_atoi_base(nbr, f_len), t_len);
	return (result);
}
