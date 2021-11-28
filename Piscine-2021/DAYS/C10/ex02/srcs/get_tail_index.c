#include "../includes/ft_tail.h"

int	get_tail_index(char *buf)
{
	int	lines;
	int	i;
	int	li;

	lines = 0;
	li = 0;
	i = 0;
	while (buf[i])
		if (buf[i++] == '\n')
			lines++;
	i = 0;
	while (buf[i] && li < (lines - 10))
		if (buf[i++] == '\n')
			li++;
	return (i);
}

/*
int	count_bytes(char *filename)
{
	char	buf;
	int	fd;
	int	lines;

	lines = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (errno);
	while (read(fd, &buf, 1))
		if (buf == '\n')
			lines++;
	close(fd);
	return (lines);
}
*/
