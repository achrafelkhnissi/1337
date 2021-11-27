#include <unistd.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
int	ft_strcmp(char *s1, char *s2);
void	sort_param(char *str[], int size);

int	main(int argc, char **argv)
{
	char	*params[argc];
	int	i;

	i = argc;
	while (--i)
		params[i] = argv[i];
	sort_param(params, argc);
	while (++i < argc)
		ft_putstr(params[i]);
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
	ft_putchar('\n');
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
			i++;

	return (s1[i] - s2[i]);
}

void	sort_param(char *str[], int size)
{
	int	i;
	char	*tmp;

	i = size;
	while (--i != 1)
	{
		if (ft_strcmp(str[i], str[i - 1]) < 0)
		{
			tmp = str[i];
			str[i] = str[i - 1];
			str[i - 1] = tmp;
			i = size;
		}
	}
}

