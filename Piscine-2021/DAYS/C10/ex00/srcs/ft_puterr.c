#include "../includes/display_file.h"

void	ft_puterr(char *err)
{
	while(*err)
		write(STDERR_FILENO, err++, 1);
}
