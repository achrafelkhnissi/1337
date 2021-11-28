#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_concat_params(int argc, char **argv);

int	main(int argc, char **argv)
{
	char	*str;

	if (argc > 1)
	{
		str = ft_concat_params(argc, argv);
		printf("%s\n", str);
	}
	return (0);
}

char	*ft_concat_params(int argc, char **argv)
{
	char	*str;
	int	len;
	int	i;
	int	j;


	i = 1;
	j = 0;
	len = 0;
	while (i < argc)
		len += strlen(argv[i++]);
	i = 1;
	str = (char *) malloc(len + argc);
	if (!str)
		return (NULL);
	while (i < argc)
	{
		str = strcat(str, argv[i]);
		if (i == argc - 1)
			str = strcat(str, "\0");
		else
			str = strcat(str, "\n");
		i++;
	}
	return (str);
}
