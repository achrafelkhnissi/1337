#include <stdio.h>

void	wdmatch(char *s1, char *s2);

int	main(int ac, char **av)
{
	if (ac == 3)
		wdmatch(av[1], av[2]);
	putchar('\n');
	return (0);
}

void	wdmatch(char *s1, char *s2)
{
	int	i;
	int	j;
	int	len;
	int	found;

	i = 0;
	j = 0;
	found = 0;
	len = 0;
	while (s1[len])
		len++;
	while (s1[i])
	{
		while (s2[j])
		{
			if (s1[i] == s2[j])
			{
				found++;
				break;
			}
			j++;
		}
		i++;
	}
	if (len == found)
		printf("%s", s1);
}
