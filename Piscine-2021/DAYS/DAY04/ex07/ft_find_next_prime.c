#include <stdio.h>

int	ft_is_prime(int nb);
int	ft_find_next_prime(int nb);
int	main(void)
{
	int	number;

	number = 0;
	while (number++ < 12)
		printf("%d next prime = %d\n",
				number, ft_find_next_prime(number));
	return (0);
}

int	ft_find_next_prime(int nb)
{
	while (!ft_is_prime(nb))
		nb++;
	return (nb);
}

int	ft_is_prime(int nb)
{
	int	p;
	
	p = 1;
	if (nb < 2)
		return (0);
	while(++p != nb)
		if (nb % p == 0) 
			return (0);
	return (1);
}

/*
 * Note: or
 * Step 1 - take square root of nb (sqrt(nb) + 1)
 * Step 2 - divide nb by numbers greter than 2 and less than or
 * 		equal to (sqrt(nb) + 1);
 */
