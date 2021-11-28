#include "../includes/ft_cat.h"

int	ft_cat(char *file)
{
	char	buf[28000];
	int	byte;
	int	fd;
	int	return_value;


	return_value = 0;
	fd = open(file, O_RDWR);
	if (fd > 0)
		while ((byte = read(fd, &buf, 28000)))
			write(STDOUT_FILENO, &buf, byte);
	else
	{
		write(STDERR_FILENO, "ft_cat: ", 8);
		write(STDERR_FILENO, file, ft_strlen(file));
		if (errno == 2)
			write(STDERR_FILENO, ": No such file or directory\n", 28);
		else if (errno == 21)
			write(STDERR_FILENO, ": Is a directory\n", 17);
		return_value = 1;
	}
	close(fd);
	return (return_value);
}
