#include "../includes/ft_tail.h"

void	stdin_to_stdout(void)
{
	char	c;

	while (read(STDIN_FILENO, &c, 1) > 0)
		write(STDIN_FILENO, &c, 1);
}
