#include <stdarg.h>
#include <stdio.h>

double	average(int count, ...)
{
	va_list ap;
	int j;
	double sum = 0;

	/* Requires the last fixed parameter (to get the address) */
	va_start(ap, count);
	for (j = 0; j < count; j++)
		sum += va_arg(ap, int); 
		/* Increments ap to the next argument. */
	va_end(ap);
	return sum / count;
}

int	main(void)
{
	printf("%f\n", average(3, 1, 2, 3));
	return 0;
}
