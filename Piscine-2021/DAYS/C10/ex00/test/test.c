#include <unistd.h>

int	main(void)
{
	char 	b[30];

	write(1, "Enter your text: ", 17);
	read(0, b, 30);
	write(1, "You Entered: ", 17);
	write(1, b, 30);
	return (0);
	return (0);
}
