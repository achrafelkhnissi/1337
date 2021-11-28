#include "ft_point.h"

void	set_point(t_point *point)
{
	point->x = 13;
	point->y = 37;
}

int	main(void)
{
	t_point	point;

	set_point(&point);
	return (0);
}
