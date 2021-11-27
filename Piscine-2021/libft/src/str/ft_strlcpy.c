#include "../../includes/libft.h"

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	d_len;
	unsigned int	s_len;

	i = 0;
	d_len = ft_strlen(dest);
	s_len = ft_strlen(src);
	if (size)
	{
		while (src[i] && (i + 1) < size)
			dest[i] = src[i], i++;
		dest[i] = '\0';
	}
	return (s_len);
}
