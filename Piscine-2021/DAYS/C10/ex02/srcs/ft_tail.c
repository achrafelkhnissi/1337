#include "../includes/ft_tail.h"

void	ft_tail(int ac, int bytes, char *file)
{
	char	buf[28000];
	char	*content;
	int	fd;
	int	size;
	int	i;

	i = 0;
	size = 0;
	fd = open(file, O_RDWR);
	if (fd > 0)
	{
		show_file_name(ac, bytes, file);
		while ((i = read(fd, buf, 28000)))
			size +=i;
		close(fd);
		content = malloc(sizeof(char) * size);
		ft_strncpy(content, buf, size);
		if (bytes)
			i = size - bytes;
		else
			i = get_tail_index(content);
		while (buf[i])
			write(1, &content[i++], 1);
		free(content);
	}
	else
	{
		write(STDERR_FILENO, "ft_tail: ", 9);
		write(STDERR_FILENO, file, ft_strlen(file));
		if (errno == 2)
			write(STDERR_FILENO, ": No such file or directory\n", 28);
		else if (errno == 21)
			write(STDERR_FILENO, ": Is a directory\n", 17);
	}
	close(fd);
}
