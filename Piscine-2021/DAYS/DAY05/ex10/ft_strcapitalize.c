#include <stdio.h>

int	is_sign(char c)
{
	if(c >= '0' && c <= '9')
		return (0);
	if(c >= 'a' && c <= 'z')
		return (0);
	if(c >= 'A' && c <= 'Z')
		return (0);
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (str[i])
	{
		if (is_sign(str[i]))
		{
			i++;
			word = 0;
		}
		else if (!word)
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] -= 32, i++;
			else
				i++;
			word = 1;
		}
		else if (word)
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] += 32, i++;
			else
				i++;
		}
	}
	return (str);
}

int	main(void)
{
	char	str[100]= "salut, comment tu vas ? 1337mots quanate-deux; cinquante+et+un";
	ft_strcapitalize(str);
	printf("%s\n", str);
	return (0);
}
