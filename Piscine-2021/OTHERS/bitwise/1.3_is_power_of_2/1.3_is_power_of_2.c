/**********************************************************************
** 1.3 : Checking if an unsigned integer is power of 2
**********************************************************************/

/*
** This a vanilla question for interviews :
** Write a function that determines if a given number is a power of 2.
** This function returns 1 if the given number is a power of 2, otherwise it returns 0.
** Your function must be declared as follows:
** int	    is_power_of_2(unsigned int n);
*/

#include "bitwise.h"

/*
** first the basic function
*/

int		is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	while (n % 2 == 0) // or alternatively (!(n % 2))
		n /= 2;
	return ((n == 1) ? 1 : 0); // equivalent to : if (n == 1) return 1; else return (0);
}

/*
** Now the bitwise version :
** we apply n - 1 mask to n, and then check that is equal to 0
** it will be true for all numbers that are power of 2.
** Lastly we make sure that n is superior to 0.
*/

int		is_power_of_2(unsigned int n)
{
    return (n > 0 && !(n & (n - 1)));
}

/*
** Test program
*/

int	main(int ac, char **av)
{
	if (ac == 2)
    {
        printf("%s is power of 2 ?");
        is_power_of_2(atoi(av[1])) ? printf("Yes\n") : printf("No\n");
    }
    return (0);
}
