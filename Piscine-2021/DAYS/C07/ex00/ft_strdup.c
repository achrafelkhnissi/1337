#include <stdlib.h>
#include <stdio.h>

char	*ft_strdup(char *src);

int	main(void)
{
	char	*name;
	char	*copy;

	name = "Future is loading!";
	copy = ft_strdup(name);
	printf("copy = %s\n", copy);
	return (0);
}

char	*ft_strdup(char *src)
{
	char	*copy;
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (src[len])
		len++;
	copy = (char *) malloc(len + 1);
	if (!copy)
		return (NULL);
	while (src[i])
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

