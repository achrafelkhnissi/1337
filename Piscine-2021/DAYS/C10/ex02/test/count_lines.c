#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int	count_lines(char *filename)
{
	char	buf[28000];
	int	fd;
	int	lines;
	int	i;

	lines = 0;
	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (errno);
	while (read(fd, buf, 28000))
		;
	while (buf[i])
		if (buf[i++] == '\n')
			lines++;
	close(fd);
	return (lines);
}

int	main(int ac, char **av)
{
	int	lines;

	if (ac != 2)
		return (1);
	lines = count_lines(av[1]);
	printf("lines: %d\n", lines);
	return (0);
}
