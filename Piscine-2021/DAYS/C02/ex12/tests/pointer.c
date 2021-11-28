#include <unistd.h>

int		char_is_printable(char c)
{
	if (c < ' ' || c > '~')
		return (0);
	return (1);
}

void	convert_hexa(unsigned char c)
{
	write(1, &"0123456789abcdef"[c / 16], 1);
	write(1, &"0123456789abcdef"[c % 16], 1);
}

void	print_content_hexa(char *str)
{
	int i;

	i = 0;
	while (str[i] && i < 16)
	{
		convert_hexa(str[i]);
		if (i % 2 == 1)
			write(1, " ", 1);
		i++;
	}
}

void	print_content_printable(char *str)
{
	int i;
	int size;
	int n_spaces;

	size = 0;
	while (str[size])
		size++;
	i = 0;
	n_spaces = (16 - size) * 2 + ((16 - size) / 2) + 1;
	while (i < n_spaces)
	{
		write(1, " ", 1);
		i++;
	}
	i = 0;
	while (str[i] && i < 16)
	{
		if (char_is_printable(str[i]))
			write(1, str + i, 1);
		else
			write(1, ".", 1);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	int				j;

	i = 0;
	while (i < size)
	{
		j = 56;
		while (j >= 0)
		{
			convert_hexa(((unsigned long)(addr + i)) >> j);
			j -= 8;
		}
		write(1, ":", 1);
		write(1, " ", 1);
		print_content_hexa(addr + i);
		print_content_printable(addr + i);
		i += 16;
		write(1, "\n", 1);
	}
	return (addr);
}

#include <stdio.h>

int main(void)
{
    char *pointer = "this is just a test.";
    
    printf("Pointer to the string = %p\n", pointer);

    ft_print_memory(pointer, 20);
    
    return (0);
}
