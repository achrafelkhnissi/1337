#include "../includes/ft_tail.h"

void	show_file_name(int ac, int bytes, char *filename)
{
	static int	i;

	if ((!bytes && ac > 2) || (bytes && ac > 4))
	{
		if (i++)
			write(1, "\n", 1);
		write(STDOUT_FILENO, "==> ", 4);
		write(STDOUT_FILENO, filename, ft_strlen(filename));
		write(STDOUT_FILENO, " <==\n", 5);
	}
}
