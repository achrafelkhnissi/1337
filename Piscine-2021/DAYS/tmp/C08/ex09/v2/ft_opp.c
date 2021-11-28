#include "ft_adv_do-op.h"

int		ft_add(int nbr1, int nbr2)
{
	return (nbr1 + nbr2);
}

int		ft_sub(int nbr1, int nbr2)
{
	return (nbr1 - nbr2);
}

int		ft_mul(int nbr1, int nbr2)
{
	return (nbr1 * nbr2);
}

int		ft_div(int nbr1, int nbr2)
{
	return (nbr2 != 0 ? nbr1 / nbr2 : 0);
}

int		ft_mod(int nbr1, int nbr2)
{
	return (nbr2 != 0 ? nbr1 % nbr2 : 0);
}
