#include <stdio.h>

int	main(void)
{
	char	*addr = "test";

	printf("addr d %d\n",(int) addr);
	printf("addr s %s\n",(char *) addr);
	printf("addr x %x\n",(int) addr);
	printf("addr p %p\n", addr);

	return (0);
}
