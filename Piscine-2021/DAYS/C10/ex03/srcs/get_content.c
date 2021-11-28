#include "../includes/ft_hexdump.h"

char	*get_content(char *file)
{
	char	buf[28000];
	char	*content;
	int	fd;
	int	size;
	int	i;

	i = 0;
	size = 0;
	content = 0;
	fd = open(file, O_RDWR);
	if (fd > 0)
	{
		while ((i = read(fd, buf, 28000)))
			size += i;
		close(fd);
		content = malloc(sizeof(char) * size);
		ft_strncpy(content, buf, size);
	}
	else
	{
		write(STDERR_FILENO, "ft_hexdump: ", 12);
		write(STDERR_FILENO, file, ft_strlen(file));
		if (errno == 2)
			write(STDERR_FILENO, ": No such file or directory\n", 28);
		else if (errno == 21)
			write(STDERR_FILENO, ": Is a directory\n", 17);
	}
	return (content);
}
