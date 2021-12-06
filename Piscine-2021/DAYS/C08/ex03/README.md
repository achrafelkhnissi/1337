## Exercise 03: ft_point.h
- Create a file __ft_point_h__ that'll compile the following main:
```c
# include "ft_point.h"

void	set_point(t_point *point)
{
	point->x = 42;
	point->y = 21;
}

int	main(void)
{
	t_point	point;

	set_point(&point);
	return (0);
}
```

