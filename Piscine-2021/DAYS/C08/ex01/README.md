## Exercise 01: ft_boolean.h
- Create a __ft_boolean.h__ file. It'll compile and run the following main appropriately:
```C
#include "ft_boolean.h"

void	ft_putchar(char *str)
{
	while(*str)
		write(1, str++, 1);
}

t_bool	ft_is_even{int nbr)
{
	return ((EVEN(nbr)) ? TRUE : FALSE);
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (ft_is_even(argc - 1) == TRUE)
		ft_putstr(EVEN_MSG);
	else
		ft_putstr(ODD_MSG);
	return (SUCCESS);
}
```
- This program should display
```
I have an even number of arguments.
```
- or
```
I have an odd number of arguments.
```
- followed by a line break when adequate.

