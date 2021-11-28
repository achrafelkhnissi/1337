#include <stdio.h>

int	get_word(char *str);
void	print_word(char *str, int i);

int	main(int ac, char **av)
{
	int	i;

	if (ac == 2)	
	{
		i = get_word(av[1]);
		print_word(av[1], i);
	}
	return (0);
}

int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

void	print_word(char *str, int i)
{
	while (str[i] && str[i] != ' ' && str[i] != '\t')
		putchar(str[i++]);
	putchar('\n');
}

int	get_word(char *str)
{
	int	i;

	i = 0;
	while (str[i + 1])
		i++;
	if (!is_space(str[i]) && is_space(str[i - 1]))
		i--;
	while (is_space(str[i]) && i) 
	{
		i--;
		if (!is_space(str[i]) && is_space(str[i - 1]))
			i--;
	}
	while (!is_space(str[i]) && i)
		i--;
	return (i + 1);
}
