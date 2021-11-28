#include "../includes/ft_hexdump.h"

int	main(int ac, char **av)
{
	char	*str;
	int	size;
	int	flag;
	int	i;

	size = 0;
	str = 0;
	i = 1;
	if (ac > 1)
	{
		flag = check_flag(av);
		if (flag == -1)
			return (flag);
		else if (flag)
			i = 2;
		while (i < ac)
		{
			str = get_content(av[i]);
			if (str && flag >= 0)
			{
				size = ft_strlen(str);
				ft_hexdump(str, size, flag);
				free(str);
			}
			i++;
		}
	}
	else
		write(2, "usage: ft_hexdump [ -C ] file ...\n", 35);
	return (0);
}
