#include <unistd.h>
#include <stdio.h>

void	last_word(char *str);
int	get_index(char *str);
int	is_space(char c);

int	main(int ac, char **av)
{
	if (ac == 2)
		last_word(av[1]);
	write(1, "\n", 1);
	return (0);
}

void	last_word(char *str)
{
	int	i;

	i = get_index(str);
	while (!is_space(str[i]) && i)
		write(1, &str[i++], 1);
}

int	get_index(char *str)
{
	int	i;

	i = 0;
	while (str[i + 1])
		i++;
	while (str[i])
	{
		if (!is_space(str[i]) && !is_space(str[i - 1]))
			break;
		i--;
	}
	while (!is_space(str[i]))
		i--;
	return (i + 1);
}

int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\0');
}
