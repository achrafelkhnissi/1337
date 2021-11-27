#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n);

int	main(int argc, char **argv)
{
	int	equal;

	equal = ft_strncmp(argv[1], argv[2], argv[3][0] - '0');
	if (argc == 4)
		printf("%d\n", equal);
	return (0);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	
	i = 0;
	if (!n)
		return (0);
	while (s1[i] == s2[i] && s1[i] && s2[i] && i < n - 1)
		i++;

	return (s1[i] - s2[i]);
}
