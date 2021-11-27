#include <stdio.h>

void	putnbr(int n);
int	main(void)
{
	putnbr(64128346);
	putchar('\n');
	return (0);
}

void	putnbr(int n)
{
	if (n < 0)
	{
		putchar('-');
		n = -n;
	}
	if (n / 10)
	{
		putnbr(n / 10);
	}
	putchar(n % 10 + '0');
}


/*
 * Note:
 * 1. Suppose input 1234
 * 2. putnbr(1234)
 * 3. n = 1234
 * 4. n < 0 = false
 * 5. n / 10 = 1234 / 10 = 123 = true
 * 6. putnbr(123)
 * 7. n = 123
 * 8. n < 0 = false
 * 9. n / 10 = 123 / 10 = 12 = true
 * 10. putnbr(12)
 * 11. n = 12
 * 12. n < 0 = false
 * 13. n / 10 = 12 / 10 = 1 = true
 * 14. putnbr(1)
 * 15. n = 1
 * 16. n < 0 = false
 * 17. n / 10 = 1 / 10 = 0 = false
 * 18. putchar(n % 10 + '0') = 1 % 10 = 1
 * 19. output = 1..
 * 20. back to step 11 and continue..
 * 21. n = 12 -> putchar(12 % 10) = 2
 * 22. output = 12..
 * 23. back to step 6 and continue..
 * 24. n = 123 -> putchar(123 % 10) = 3
 * 25. output = 123..
 * 26. back to step 2 and continue..
 * 27. n = 1234 -> putchar(1234 % 10) = 4
 * 28. output = 1234.
 * 29. end of the program.
 */
