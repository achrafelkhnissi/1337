#include <stdio.h>
#include <string.h>

#define buffer 40

void	test(int size);
int	ft_strlen(char *str);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);

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
	char dest[buffer] = "no future";
	char src[] = "Future is loading!";
	int r;

	r = ft_strlcpy(dest, src, size);
	printf("dest '%s'\nsrc '%s'\nSize '%d'\n", dest, src, r);
	putchar('\n');
}

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
