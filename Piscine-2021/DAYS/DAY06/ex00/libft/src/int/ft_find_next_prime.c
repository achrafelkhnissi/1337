#include "../../includes/libft.h"

int	ft_find_next_prime(int nb)
{
	while (!ft_is_prime(nb))
		nb++;
	return (nb);
}

/*
 * Note: or
 * Step 1 - take square root of nb (sqrt(nb) + 1)
 * Step 2 - divide nb by numbers greter than 2 and less than or
 * 		equal to (sqrt(nb) + 1);
 */
