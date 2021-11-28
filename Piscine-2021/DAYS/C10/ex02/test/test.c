#include "../includes/ft_tail.h"
#define USERNAME_SIZE 10

int main()
{
	
	int fd;
  	char c;
	char username[USERNAME_SIZE];
	int count = 0;
	
	fd = open("user.dat", O_CREAT | O_RDWR, 0666);
	if (fd == -1)
		write(1,"There is an error opening the file",35);
	write(1 ,"Enter the username: ", 20);
	do
	{
		read(0, &c, 1);
		if (c == '\n')
			break;
		username[count++] = c;
	}
	while (count < USERNAME_SIZE - 1);
	username[count] = 0;
	write(fd, username, count);
	close(fd);
	return 0;
}
