#include "../includes/ft_cat.h"

void	stdin_to_stdout(void)
{
	char	c;

	while (read(STDIN_FILENO, &c, 1) > 0)
		write(STDOUT_FILENO, &c, 1);
}
