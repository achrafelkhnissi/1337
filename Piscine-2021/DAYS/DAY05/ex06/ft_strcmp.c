#include <stdio.h>

int	ft_strcmp(char *s1, char *s2);
int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		int equal = ft_strcmp(argv[1], argv[2]);
		printf("result = %d\n", equal);
	}
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
			i++;

	return (s1[i] - s2[i]);
}

