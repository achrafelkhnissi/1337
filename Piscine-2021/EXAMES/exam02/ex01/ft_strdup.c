#include <stdlib.h>

char    *ft_strdup(char *src)
{
	char	*copy;
	int	i;

	i = 0;
	while (src[i])
		i++;
	copy = malloc((sizeof(copy) * i) + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while ((copy[i] = src[i]) != '\0')
		i++;
	copy[i] = '\0';
	return (copy);
}
