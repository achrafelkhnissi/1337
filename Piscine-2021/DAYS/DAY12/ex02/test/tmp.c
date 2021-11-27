#include "../includes/ft_tail.h"

int	get_tail_index(char *filename)
{
	char	buf[28000];
	int	fd;
	int	lines;
	int	i;
	int	li;

	lines = 0;
	li = 0;
	i = 0;
	fd = open(filename, O_RDWR);
	if (fd == -1)
		return (errno);
	while (read(fd, buf, 28000))
		;
	while (buf[i])
		if (buf[i++] == '\n')
			lines++;
	i = 0;
	while (buf[i] && li < (lines - 10))
		if (buf[i++] == '\n')
			li++;
	close(fd);
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
