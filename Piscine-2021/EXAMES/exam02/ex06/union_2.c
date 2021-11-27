#include <stdio.h>
#include <unistd.h>

void	ft_union(char *s1, char *s2);
int	found(char c, char *str, int index);

int	main(int ac, char **av)
{
	if (ac == 3)
		ft_union(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}

void	ft_union(char *s1, char *s2)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = 0;
	while (s1[len])
		len++;
	while (s1[i])
	{
		if (!found(s1[i], s1, i))
			write(1, &s1[i], 1);
		i++;
	}
	while (s2[j])
	{
		if (!found(s2[j], s2, j) && !found(s2[j], s1, len))
			write(1, &s2[j], 1);
		j++;
	}
}

int	found(char c, char *str, int index)
{
	int	j;

	j = 0;
	while (j < index)
		if (c == str[j++])
			return (1);
	return (0);
}
