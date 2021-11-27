#include "../../includes/libft.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	d;
	unsigned int	s;
	unsigned int	s_len;
	unsigned int	d_len;

	d_len = ft_strlen(dest);
	d = ft_strlen(dest);
	s_len = ft_strlen(src);
	s = 0;
	if (size < d)
		return (size + s_len);
	while (src[s] && d + 1 < size)
		dest[d++] = src[s++];
	dest[d] = '\0';
	return (s_len + d_len);
}

