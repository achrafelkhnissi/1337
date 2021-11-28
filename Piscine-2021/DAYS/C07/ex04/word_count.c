#include <stdio.h>

int	ft_iswhitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r')
		return (1);
	return (0);
}

int	word_count(char *str)
{
	int	i;
	int	w_count;
	int	state;

	i = 0;
	w_count = 0;
	state = 0;
	while (str[i])
	{
		if (!ft_iswhitespace(str[i]))
		{
			if (!state)
				w_count++;
			state = 1;
			i++;
		}
		else
		{
			state = 0;
			i++;
		}
	}
	return (w_count);
}

int	main(void)
{
	char	*str = "Future is loading!";
	int	words;

	words = word_count(str);
	printf("str = %s\n", str);
	printf("words = %d\n", words);
	return (0);
}

