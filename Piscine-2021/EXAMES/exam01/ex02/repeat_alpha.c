#include <stdio.h>
#include <unistd.h>

void	repeat_alpha(char *str);
int	get_alpha_index(char c);

int	main(int ac, char **av)
{
	if (ac == 2)
		repeat_alpha(av[1]);
	write(1, "\n", 1);
	return (0);
}

int	is_alpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int	get_alpha_index(char c)
{
	int	letter;
	int	i;

	letter = 'a';
	i = 0;
	if (c >= 'A' && c <= 'Z')
		c += 32;
	while (letter != c)
	{
		letter++;
		i++;
	}
	return (i);
}

void	repeat_alpha(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (is_alpha(str[i]))
		{
			j = get_alpha_index(str[i]);
			while (j--)
				write(1, &str[i], 1);
		}
		write(1, &str[i], 1);
		i++;
	}
}
