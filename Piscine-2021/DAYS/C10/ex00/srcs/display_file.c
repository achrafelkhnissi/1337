#include "../includes/display_file.h"

void	display_file(char *file)
{
	int	fd;
	char	buf;

	fd = open(file, O_RDONLY);
	if (fd > 0)
		while (read(fd, &buf, 1))
			write(STDOUT_FILENO, &buf, 1); 
	close(fd);
}

