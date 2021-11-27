#include <stdio.h>
#include <string.h>

#define buffer 40

void	test(int size);
int	ft_strlen(char *str);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

int	main(void)
{
	puts("< the length of dest");
	test(0);
	test(4);
	puts("= the length of dest");
	test(10);
	puts("< the length of src");
	test(26);
	puts("= dest length & src length");
	test(33);
	puts("= (dest length & src length) + 1");
	test(34);
	puts("= buffer");
	test(40);

	return(0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	test(int size)
{
	printf("Size = %d\n", size);
	char dest[buffer] = "This is ";
	char src[] = "a potentially long string";
	int r;

	r = ft_strlcat(dest, src, size);
	printf("dest '%s'\nsrc '%s'\nSize '%d'\n", src, dest, r);
	putchar('\n');
}

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

