char	*ft_strcat(char *dest, char *src)
{
	int	d;
	int	s;

	d = 0;
	s = 0;
	while (dest[d])
		d++;
	while (src[s])
		dest[d++] = src[s++];
	dest[d] = '\0';
	return (dest);
}

/*
 * V2:
   	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (dest);
*/
